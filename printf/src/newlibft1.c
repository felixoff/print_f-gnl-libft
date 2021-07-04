/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlibft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:39:51 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:40:29 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_newstr(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] != s1[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void		ft_delstr(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
}

void		ft_putstr(char const *s)
{
	while (*s)
		write(1, s++, 1);
}
