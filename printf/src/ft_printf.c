/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:39:06 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:39:44 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printf2(char *f, va_list *av, int *size)
{
	char	*s;
	int		i;

	s = NULL;
	i = -1;
	while (f[++i])
	{
		if (ft_strchr("sSpdDioOuUxXcC%", f[i])
		|| (ft_isalpha(f[i]) && !ft_strchr("sSpdDioOuUxXcC%", f[i])))
		{
			s = ft_strndup(f, ++i);
			break ;
		}
	}
	if (!s)
		return (0);
	*size += deterflags(s, av);
	ft_delstr(&s);
	return (i);
}

static int		printf1(char *f, va_list *av, int *size)
{
	int		*p;

	p = 0;
	while (*f)
	{
		if (*f != '%')
			*size += write(1, f++, 1);
		else
		{
			if (f++ && *f == 'n')
			{
				p = va_arg(*av, int*);
				*p = *size;
				f++;
			}
			else
				f += printf2(f, av, size);
		}
	}
	return (*size);
}

int				ft_printf(const char *format, ...)
{
	va_list		av;
	int			size;

	size = 0;
	if (!format)
		return (size);
	va_start(av, format);
	size = printf1((char *)format, &av, &size);
	va_end(av);
	return (size);
}
