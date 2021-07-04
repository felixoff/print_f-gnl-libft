/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:14:21 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:27:48 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n)
{
	int			len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

char			*ft_itoa(int j)
{
	char		*a;
	int			i;
	int			sign;
	long		n;

	sign = 1;
	n = j;
	i = ft_intlen(n);
	if (!(a = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		sign = -1;
	}
	a[i--] = '\0';
	while (i > 0)
	{
		a[i--] = ((n * sign) % 10) + 48;
		n = n / 10;
	}
	if (sign != -1)
		a[i] = ((n * sign) % 10) + 48;
	return (a);
}
