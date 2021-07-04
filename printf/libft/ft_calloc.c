/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:18:32 by sjennett          #+#    #+#             */
/*   Updated: 2020/10/31 15:10:11 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char		*a;
	size_t		i;

	a = malloc(size * count);
	i = 0;
	if (a != NULL)
	{
		while (i < count * size)
		{
			a[i] = 0;
			i++;
		}
		return (a);
	}
	return (NULL);
}
