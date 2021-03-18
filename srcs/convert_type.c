/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 03:43:56 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 00:28:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_type(va_list *args, t_struct *f)
{
	if (f->type == 'i' || f->type == 'd')
		ft_printf_int(args, f);
	if (f->type == 's')
		ft_printf_str(args, f);
	if (f->type == 'c')
		ft_printf_char(args, f);
	if (f->type == 'x')
		ft_printf_x(args, f);
	if (f->type == 'X')
		ft_printf_xx(args, f);
	if (f->type == 'u')
		ft_printf_unsigned(args, f);
	if (f->type == '%')
		ft_printf_percent(f);
	if (f->type == 'p')
		ft_printf_pointer(args, f);
}
