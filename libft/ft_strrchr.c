/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:40:04 by sjennett          #+#    #+#             */
/*   Updated: 2020/10/31 18:32:26 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*a;
	unsigned char	b;
	int				i;

	a = (char *)s;
	b = (unsigned char)c;
	i = 0;
	while (a[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (a[i] == b)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
