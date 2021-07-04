/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:47:15 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/01 19:28:43 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putnbr_fd(int nb, int fd)
{
	unsigned int nn;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	nn = (unsigned int)nb;
	if (nn > 9)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd(nn % 10 + 48, fd);
}
