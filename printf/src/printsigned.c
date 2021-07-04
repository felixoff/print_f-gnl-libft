/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:43:22 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/16 13:59:46 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		signed_type(va_list *av)
{
	return (intmax_t)va_arg(*av, int);
}

static int		helperint(t_flags *flag, char **s, int length, intmax_t type)
{
	char *tmp;

	tmp = NULL;
	if (flag->space && *s[0] != '-' && !flag->plus)
	{
		tmp = ft_strjoin(" ", *s);
		ft_delstr(s);
		*s = ft_strdup(tmp);
		ft_delstr(&tmp);
	}
	if (flag->plus && type >= 0)
	{
		tmp = ft_strjoin("+", *s);
		ft_delstr(s);
		*s = ft_strdup(tmp);
		ft_delstr(&tmp);
	}
	s_width(s, flag);
	ft_putstr(*s);
	length = ft_strlen(*s);
	ft_delstr(s);
	return (length);
}

int				printsnumber(t_flags *flag, intmax_t type)
{
	int			length;
	char		*s;

	length = 0;
	if (!flag->precision && !type)
		return (i_width(0, flag));
	s = ft_itoa(type);
	flag->length = ft_strlen(s);
	if (flag->zero && !flag->setprecision && !flag->minus
	&& (unsigned int)flag->length < (unsigned int)flag->width)
	{
		flag->setprecision = true;
		flag->precision = (flag->plus
		|| type < 0 || flag->space) ? flag->width - 1 : flag->width;
	}
	i_precision(&s, flag);
	return (helperint(flag, &s, length, type));
}
