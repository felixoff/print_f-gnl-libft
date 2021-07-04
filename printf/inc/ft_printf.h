/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:56:34 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/15 19:37:02 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct		s_flags
{
	bool			pound;
	bool			zero;
	bool			minus;
	bool			space;
	bool			plus;
	bool			setwidth;
	bool			setprecision;
	int				width;
	int				precision;
	int				length;
	char			spec;
}					t_flags;

int					ft_printf(const char *format, ...);
int					deterflags(char *s, va_list *av);
int					ft_abs(int n);
int					ft_abs(int n);
int					ft_strcmp(char *s1, char*s2);
char				*ft_strcpy(char *dest, char *src);
void				*ft_callocnew(size_t size);
int					printsnumber(t_flags *flag, intmax_t type);
void				i_precision(char **s, t_flags *flag);
intmax_t			signed_type(va_list *av);
int					specify (t_flags *flag, va_list *av);
int					specifysymbol (t_flags *flag, va_list *av);
int					specifynumber(t_flags *flag, va_list *av);
int					printstring(t_flags *flag, va_list *av, int length);
int					printchar(t_flags *flag, va_list *av, int length);
int					i_width(unsigned int i, t_flags *flag);
void				s_precision(char **s, t_flags *flag);
void				s_width(char **s, t_flags *flag);
int					printunumber(t_flags *flag, unsigned long long type);
char				*ft_itoa_u(unsigned long long nb, unsigned int base);
int					printhex(t_flags *flag, unsigned long long type);
void				ft_putdowncase(char *s);
unsigned long long	unsigned_type(va_list *av);
int					printpoint(t_flags *flag, va_list *av);
int					printinvalid(t_flags *flag);
int					printpercent(t_flags *flag, va_list *av);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_strndup(const char *s, size_t n);
void				ft_putstr(char const *s);
void				ft_delstr(char **s);
char				*ft_newstr(size_t size);

#endif
