/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:46:20 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:49:38 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			specifyunumber(t_flags *flag, va_list *av)
{
	if (flag->spec == 'u')
	{
		flag->spec = 'u';
		return (printunumber(flag, unsigned_type(av)));
	}
	return (printhex(flag, unsigned_type(av)));
}

int					specifynumber(t_flags *flag, va_list *av)
{
	if (flag->spec == 'd' || flag->spec == 'i')
	{
		flag->spec = 'd';
		return (printsnumber(flag, signed_type(av)));
	}
	return (specifyunumber(flag, av));
}

int					specifysymbol(t_flags *flag, va_list *av)
{
	if (flag->spec == 's')
		return (printstring(flag, av, 0));
	else if (flag->spec == 'c')
		return (printchar(flag, av, 0));
	else if (flag->spec == 'p')
		return (printpoint(flag, av));
	return (printpercent(flag, av));
}

int					specify(t_flags *flag, va_list *av)
{
	if (ft_strchr("idDxXouUO", flag->spec))
		return (specifynumber(flag, av));
	else if (ft_strchr("SscCp%", flag->spec))
		return (specifysymbol(flag, av));
	return (printinvalid(flag));
}
