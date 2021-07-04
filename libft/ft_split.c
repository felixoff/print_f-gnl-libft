/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:09 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:29:08 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsize(char const *s, char c)
{
	unsigned int		i;
	int					len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (len);
}

static char		**ft_strsize_2(char const *s, char c, int i, int j)
{
	char	**a;
	int		len;
	int		k;

	len = 0;
	if (!(a = (char**)malloc(sizeof(char*) * (ft_strsize(s, c) + 1))))
		return (NULL);
	while (s[i] && j < ft_strsize(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		if (!(a[j] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		k = 0;
		while (len)
			a[j][k++] = s[i - len--];
		a[j++][k] = '\0';
	}
	a[j] = NULL;
	return (a);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**a;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	a = ft_strsize_2(s, c, i, j);
	return (a);
}
