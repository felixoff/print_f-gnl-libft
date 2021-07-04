/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:30:14 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:30:26 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	int				i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (!(a = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	a[i] = '\0';
	i--;
	while (i >= 0)
	{
		a[i] = (*f)(i, s[i]);
		i--;
	}
	return (a);
}
