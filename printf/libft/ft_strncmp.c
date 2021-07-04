/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:35:00 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:26:41 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char *)s1;
	s21 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s2[i] != s1[i])
		{
			return (s11[i] - s21[i]);
		}
		if (s21[i] == '\0' || s11[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
