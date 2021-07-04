/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:42:45 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/05 14:05:16 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*a;

	i = start;
	if (!s)
		return (NULL);
	if (i >= ft_strlen(s))
		a = malloc(0 + 1);
	else
		a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (i < ft_strlen(s) && i < start + len)
	{
		a[i - start] = s[i];
		i++;
	}
	a[i - start] = '\0';
	return (a);
}
