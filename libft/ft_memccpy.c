/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:18:25 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/04 15:38:33 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	d;
	size_t			i;

	b = (unsigned char *)src;
	a = (unsigned char *)dst;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
		if (a[i - 1] == d)
		{
			dst++;
			return (dst);
		}
		dst++;
	}
	return (NULL);
}
