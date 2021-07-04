/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlibft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:40:37 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:41:51 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char*)malloc(sizeof(char) * n);
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if ((str = ft_newstr(len)) == NULL)
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char		*ft_itoa_u(unsigned long long nb, unsigned int base)
{
	char				*s;
	int					length;
	unsigned long long	val;
	const char			base_s[16] = "0123456789ABCDEF";

	val = nb;
	length = 1;
	while (val >= base)
	{
		length++;
		val = val / base;
	}
	s = (char*)malloc(sizeof(char) * (length + 1));
	s[length] = '\0';
	while (0 < length--)
	{
		s[length] = base_s[nb % base];
		nb = nb / base;
	}
	return (s);
}

int			ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

void		*ft_callocnew(size_t size)
{
	void *a;

	if (!(a = (void *)malloc(size)))
		return (NULL);
	ft_memset(a, 0, size);
	return (a);
}
