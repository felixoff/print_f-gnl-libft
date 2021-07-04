/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstrandchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:44:11 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:44:46 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printchar(t_flags *flag, va_list *av, int length)
{
	char		*s;
	int			flag2;
	int			num;

	flag2 = 0;
	num = va_arg(*av, int);
	s = ft_newstr(1);
	if (flag->minus && !num)
		length += write(1, "\0", 1);
	if (num == 0)
		flag2 = 1;
	else
		s[0] = num;
	flag->width -= flag->width > 0 ? flag2 : 0;
	s_width(&s, flag);
	length += ft_strlen(s);
	ft_putstr(s);
	if (flag2 && !flag->minus)
		length += write(1, "\0", 1);
	ft_delstr(&s);
	return (length);
}

static int		helper(char **s, t_flags *flag, int length)
{
	flag->length = ft_strlen(*s);
	s_precision(s, flag);
	s_width(s, flag);
	length = ft_strlen(*s);
	ft_putstr(*s);
	ft_delstr(s);
	return (length);
}

int				printstring(t_flags *flag, va_list *av, int length)
{
	char	*s;
	char	*tmp;
	char	*arg;

	s = NULL;
	tmp = NULL;
	if (!(arg = va_arg(*av, char*)))
	{
		if (!flag->setprecision || (flag->setprecision && flag->precision))
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	if (s)
	{
		tmp = ft_strdup(s);
		ft_delstr(&s);
	}
	s = ft_strdup(tmp ? tmp : arg);
	if (tmp)
		ft_delstr(&tmp);
	return (helper(&s, flag, length));
}
