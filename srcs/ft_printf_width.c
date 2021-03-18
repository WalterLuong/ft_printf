/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:34:55 by wluong            #+#    #+#             */
/*   Updated: 2020/11/11 20:45:23 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_width(t_struct *f)
{
	while (f->width > 0)
	{
		ft_putchar(' ');
		f->compteur++;
		f->width--;
	}
}

void	ft_printf_zwidth(t_struct *f)
{
	while (f->zero_width > 0)
	{
		ft_putchar('0');
		f->compteur++;
		f->zero_width--;
	}
}
