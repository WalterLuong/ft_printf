/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:35:44 by wluong            #+#    #+#             */
/*   Updated: 2021/03/18 12:45:53 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct		s_struct
{
	int		i;
	int		compteur;
	char	type;
	int		minus;
	int		zero;
	int		zero_width;
	int		width;
	int		dot;
	int		precision;
}					t_struct;

t_struct			*parsing_init(t_struct *f);
void				re_init(t_struct *f);

void				parsing(const char *input, t_struct *f, va_list *args);
void				parsing_flags(const char *input, t_struct *f);
void				parsing_width(const char *input, t_struct *f,
va_list *args);
void				parsing_dot(const char *input, t_struct *f, va_list *args);

void				ft_printf_int(va_list *args, t_struct *f);
void				ft_printf_str(va_list *args, t_struct *f);
void				ft_printf_char(va_list *args, t_struct *f);
void				ft_printf_x(va_list *args, t_struct *f);
void				ft_printf_xx(va_list *args, t_struct *f);
void				ft_printf_unsigned(va_list *args, t_struct *f);
void				ft_printf_pointer(va_list *args, t_struct *f);
void				ft_printf_percent(t_struct *f);

void				ft_printf_width(t_struct *f);
void				ft_printf_zwidth(t_struct *f);

void				convert_type(va_list *args, t_struct *f);
void				check_error(t_struct *f);

int					ft_printf(const char *input, ...);

#endif
