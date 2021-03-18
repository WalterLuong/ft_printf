/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:16:47 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 00:30:18 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_percent(t_struct *f)
{
	f->width--;
	if (f->minus == 1)
	{
		ft_putchar('%');
		f->compteur++;
		ft_printf_width(f);
	}
	else if (f->zero == 1)
	{
		while (f->width > 0)
		{
			ft_putchar('0');
			f->compteur++;
			f->width--;
		}
		ft_putchar('%');
		f->compteur++;
	}
	else if (f->minus == 0 && f->zero == 0)
	{
		ft_printf_width(f);
		ft_putchar('%');
		f->compteur++;
	}
}
