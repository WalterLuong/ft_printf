/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 03:36:15 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 04:24:17 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_error(t_struct *f)
{
	if (f->type == 'd' || f->type == 'i' || f->type == 'x' ||
	f->type == 'X' || f->type == 'u' || f->type == 'p')
	{
		if (f->zero == 1 && f->minus == 1)
			f->zero = 0;
		if (f->zero == 1 && f->dot == 1)
			f->zero = 0;
	}
	if (f->type == 's')
	{
		if (f->zero == 1 && f->minus == 1)
			f->zero = 0;
	}
	if (f->type == '%')
	{
		if (f->dot == 1)
			f->dot = 0;
		if (f->minus == 1 && f->zero == 1)
			f->zero = 0;
	}
}
