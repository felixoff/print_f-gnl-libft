/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:23:32 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:18:34 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s21;
	size_t			i;

	s11 = (unsigned char *)s1;
	s21 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s21[i] != s11[i])
		{
			return (s11[i] - s21[i]);
		}
		i++;
	}
	return (0);
}
