/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:24 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:30:49 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_start(const char *s, const char *set)
{
	int		j;
	int		i;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s[i] == set[j])
				k++;
			j++;
		}
		if (k == 0)
			return (i);
		j = 0;
		k = 0;
		i++;
	}
	return (i);
}

static int		ft_fin(const char *s, const char *set)
{
	int j;
	int i;
	int k;

	j = 0;
	k = 0;
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		while (set[j] != '\0')
		{
			if (s[i] == set[j])
				k++;
			j++;
		}
		if (k == 0)
			return (i);
		j = 0;
		k = 0;
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int k;
	char*a;

	k = 0;
	if (!s1 || !set)
		return (NULL);
	i = ft_start(s1, set);
	j = ft_fin(s1, set);
	if (j == -1)
	{
		a = "";
		return (ft_calloc(1, 1));
	}
	if (!(a = (char*)malloc(sizeof(char) * ((j - i + 1) + 1))))
		return (NULL);
	while (i <= j)
	{
		a[k] = s1[i];
		k++;
		i++;
	}
	a[k] = '\0';
	return (a);
}
