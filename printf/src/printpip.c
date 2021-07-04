/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:42:04 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:43:12 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printpercent(t_flags *flag, va_list *av)
{
	char	*s;
	int		length;

	length = 0;
	(void)av;
	s = ft_strdup("%");
	s_width(&s, flag);
	length = ft_strlen(s);
	ft_putstr(s);
	ft_delstr(&s);
	return (length);
}

int			printinvalid(t_flags *flag)
{
	char	*s;

	s = ft_newstr(1);
	if (flag->minus || flag->space || !flag->setwidth || !flag->setprecision)
	{
		s[0] = flag->spec;
		s_width(&s, flag);
	}
	else
	{
		s_width(&s, flag);
		s[ft_strlen(s) - 1] = flag->spec;
	}
	ft_putstr(s);
	ft_delstr(&s);
	return (flag->width);
}

static int	null(t_flags *flag, char **p)
{
	i_precision(p, flag);
	if (flag->zero)
	{
		flag->width -= 2;
		s_width(p, flag);
	}
	if (!flag->precision && flag->setprecision)
		*p = ft_strdup("");
	*p = ft_strjoin("0x", *p);
	if (!flag->zero)
		s_width(p, flag);
	return (ft_strlen(*p));
}

static int	validpoint(t_flags *flag, char **p)
{
	char	*tmp;

	i_precision(p, flag);
	if (flag->pound && flag->setprecision)
		flag->zero = 0;
	tmp = ft_strjoin("0x", *p);
	ft_delstr(p);
	*p = ft_strdup(tmp);
	ft_delstr(&tmp);
	s_width(p, flag);
	return (ft_strlen(*p));
}

int			printpoint(t_flags *flag, va_list *av)
{
	char		*p;
	int			length;

	length = 0;
	p = va_arg(*av, void *);
	p = ft_itoa_u((unsigned long long)p, 16);
	flag->length = ft_strlen(p);
	length = ft_strcmp(p, "0") ? validpoint(flag, &p) : null(flag, &p);
	ft_putdowncase(p);
	ft_delstr(&p);
	return (length);
}
