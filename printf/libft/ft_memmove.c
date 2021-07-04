/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:27:12 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 20:07:37 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (a == NULL && b == NULL)
		return (NULL);
	if (a < b)
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	else
	{
		while (len > 0)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	return (dst);
}
