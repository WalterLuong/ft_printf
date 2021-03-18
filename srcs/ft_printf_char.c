/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:56:20 by wluong            #+#    #+#             */
/*   Updated: 2020/11/11 18:33:36 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_char(va_list *args, t_struct *f)
{
	int c;

	c = va_arg(*args, int);
	f->width = f->width - 1;
	if (f->minus == 1)
	{
		ft_putchar(c);
		f->compteur++;
		ft_printf_width(f);
	}
	else if (f->minus == 0)
	{
		ft_printf_width(f);
		ft_putchar(c);
		f->compteur++;
	}
}
