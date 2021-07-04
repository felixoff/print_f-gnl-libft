/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:37:59 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:38:57 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		deterprecision(char *s, t_flags *flag, va_list *av)
{
	int num;

	while (*s)
	{
		if (*s == '*' && !ft_isdigit(*(s + 1)))
		{
			num = va_arg(*av, int);
			if (*(s - 1) == '.')
			{
				flag->setprecision = (num >= 0) ? true : false;
				flag->precision = (num >= 0) ? num : -1;
			}
			else
			{
				flag->minus = (num < 0) ? true : flag->minus;
				flag->setwidth = true;
				flag->width = ft_abs(num);
			}
		}
		else if (*s == '*')
			num = va_arg(*av, int);
		s++;
	}
}

static void		deterwidth(char *s, t_flags *flag)
{
	flag->width = 1;
	flag->precision = 1;
	while (*s)
	{
		if (*s != '.' && *s != '0' && ft_isdigit(*s))
		{
			flag->setwidth = true;
			flag->width = ft_atoi(s);
			while (*s && ft_isdigit(*s))
				s++;
		}
		if (*s == '.' && *(s + 1) != '*')
		{
			flag->setprecision = true;
			flag->precision = ft_atoi(s + 1);
			while (*s && ft_isdigit(*(s + 1)))
				s++;
		}
		s++;
	}
}

int				deterflags(char *s, va_list *av)
{
	int			i;
	t_flags		*flag;

	i = -1;
	flag = (t_flags *)ft_callocnew(sizeof(t_flags));
	flag->spec = s[ft_strlen(s) - 1];
	while (s[++i])
	{
		if (s[i] == '0' && s[i - 1] != '.' && !ft_isdigit(s[i - 1]))
			flag->zero = true;
		flag->pound = (s[i] == '#') ? true : flag->pound;
		flag->plus = (s[i] == '+') ? true : flag->plus;
		flag->minus = (s[i] == '-') ? true : flag->minus;
		flag->space = (s[i] == ' ') ? true : flag->space;
	}
	deterwidth(s, flag);
	deterprecision(s, flag, av);
	i = specify(flag, av);
	free(flag);
	flag = NULL;
	return (i);
}
