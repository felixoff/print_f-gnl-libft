/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:04:45 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/04 16:04:49 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int ret;

	ret = 0;
	while (lst)
	{
		ret++;
		lst = lst->next;
	}
	return (ret);
}
