/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsignedandhex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:44:54 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/16 13:59:21 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		unsigned_type(va_list *av)
{
	return (unsigned long long)va_arg(*av, unsigned int);
}

void					ft_putdowncase(char *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
	{
		if (s[i] <= 98 && s[i] >= 65)
			s[i] = s[i] + 32;
		write(1, &s[i], 1);
	}
}

static int				valid(t_flags *flag, int length, char *s)
{
	char *tmp;

	tmp = NULL;
	flag->length = ft_strlen(s);
	i_precision(&s, flag);
	if (flag->zero && flag->pound)
	{
		flag->width -= 2;
		s_width(&s, flag);
	}
	if (ft_strcmp("0", s) && flag->pound)
	{
		tmp = ft_strjoin("0X", s);
		ft_delstr(&s);
		s = ft_strdup(tmp);
		ft_delstr(&tmp);
	}
	s_width(&s, flag);
	!(flag->spec == 'X') ? ft_putdowncase(s) : ft_putstr(s);
	length = ft_strlen(s);
	ft_delstr(&s);
	return (length);
}

int						printhex(t_flags *flag, unsigned long long type)
{
	char	*s;
	int		length;

	length = 0;
	if (type)
		return (valid(flag, length, ft_itoa_u(type, 16)));
	s = ft_newstr(1);
	if (flag->setprecision && !flag->precision)
		s[0] = 0;
	else
		s = ft_strjoin("0", s);
	i_precision(&s, flag);
	s_width(&s, flag);
	ft_putstr(s);
	length = ft_strlen(s);
	ft_delstr(&s);
	return (length);
}

int						printunumber(t_flags *flag, unsigned long long type)
{
	char	*s;
	int		length;

	if (!flag->precision && !type)
	{
		if (!flag->setwidth)
			return (0);
		s = ft_newstr(flag->width);
		ft_memset(s, ' ', flag->width);
		ft_putstr(s);
		length = ft_strlen(s);
		ft_delstr(&s);
		return (length);
	}
	else
	{
		s = ft_itoa_u(type, 10);
		flag->length = ft_strlen(s);
		i_precision(&s, flag);
		s_width(&s, flag);
		ft_putstr(s);
		length = ft_strlen(s);
		ft_delstr(&s);
		return (length);
	}
}
