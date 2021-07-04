/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widandprec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:47:11 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:48:02 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*justific(char **s, t_flags *flag, char *tmp)
{
	if (ft_strchr("%", flag->spec) && flag->zero)
		ft_memset(tmp, '0', flag->width - ft_strlen(*s));
	else if (flag->setprecision)
		flag->zero = false;
	if (!flag->zero)
		ft_memset(tmp, ' ', flag->width - ft_strlen(*s));
	else
	{
		if (*s[0] == '-' || flag->space)
		{
			ft_memset(tmp, '0', flag->width - ft_strlen(*s) + 1);
			tmp[0] = flag->space ? ' ' : '-';
			*s = ft_strsub(*s, 1, ft_strlen(*s) - 1);
			tmp = ft_strjoin(tmp, *s);
		}
		else
			ft_memset(tmp, '0', flag->width - ft_strlen(*s));
	}
	ft_strcpy(tmp + flag->width - ft_strlen(*s), *s);
	return (tmp);
}

void			s_width(char **s, t_flags *flag)
{
	char *tmp;

	if (!flag->setwidth || (unsigned int)flag->width <= ft_strlen(*s))
		return ;
	tmp = ft_newstr(flag->width);
	if (!flag->minus)
		tmp = justific(s, flag, tmp);
	else
	{
		ft_strcpy(tmp, *s);
		ft_memset(tmp + ft_strlen(*s), ' ', flag->width - ft_strlen(*s));
	}
	ft_delstr(s);
	*s = ft_strdup(tmp);
	ft_delstr(&tmp);
}

void			s_precision(char **s, t_flags *flag)
{
	if (!flag->setprecision || flag->length <= flag->precision)
		return ;
	*s = ft_strndup(*s, flag->precision);
}

int				i_width(unsigned int i, t_flags *flag)
{
	int		length;
	char	*s;

	length = 0;
	if (!flag->setwidth)
		return (length);
	s = ft_newstr(flag->width);
	flag->width < 0 ? ft_memset(s, ' ', i) : ft_memset(s, ' ', flag->width - i);
	length = ft_strlen(s);
	ft_putstr(s);
	ft_delstr(&s);
	return (length);
}

void			i_precision(char **s, t_flags *flag)
{
	char *tmp;

	if (!flag->setprecision || flag->length > flag->precision)
		return ;
	tmp = ft_newstr(flag->precision);
	flag->zero = false;
	if (*s[0] == '-')
	{
		ft_memset(tmp, '0', flag->precision - (ft_strlen(*s) - 1));
		tmp = ft_strjoin("-", tmp);
		*s = ft_strsub(*s, 1, ft_strlen(*s) - 1);
		tmp = ft_strjoin(tmp, *s);
		ft_delstr(s);
		*s = tmp;
		return ;
	}
	ft_memset(tmp, '0', flag->precision - flag->length);
	ft_strcpy(tmp + flag->precision - ft_strlen(*s), *s);
	ft_delstr(s);
	*s = tmp;
}
