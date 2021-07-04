/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:36:18 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/05 14:20:34 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	scmp(const char *s1, const char *s2)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		len1;

	i = -1;
	len1 = ft_strlen(needle);
	if (!len1)
		return ((char*)haystack);
	if (len1 > ft_strlen(haystack) || len < len1)
		return (NULL);
	while (haystack[++i] && i <= len - len1)
		if (scmp(haystack + i, needle))
			return ((char*)haystack + i);
	return (NULL);
}
