/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:37:14 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 13:59:39 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	minus_pointer(t_struct *f, char *itoa_base, int len)
{
	f->compteur = f->compteur + ft_putwstr("0x", 2);
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
	ft_printf_width(f);
}

void	nflag_pointer(t_struct *f, char *itoa_base, int len)
{
	ft_printf_width(f);
	f->compteur = f->compteur + ft_putwstr("0x", 2);
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
}

void	zero_pointer(t_struct *f, char *itoa_base, int len)
{
	f->compteur = f->compteur + ft_putwstr("0x", 2);
	while (f->width > 0)
	{
		ft_putchar('0');
		f->compteur++;
		f->width--;
	}
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
}

void	ft_printf_pointer(va_list *args, t_struct *f)
{
	unsigned long		num;
	char				*itoa_base;
	int					len;

	num = (unsigned long)va_arg(*args, void *);
	itoa_base = ft_itoa_base(num, "0123456789abcdef");
	len = ft_strlen(itoa_base);
	if (f->dot == 1 && f->precision > 0)
		f->zero_width = f->precision - len;
	if (f->dot == 1 && f->precision <= 0 && num == 0)
	{
		itoa_base[0] = '\0';
		f->width++;
	}
	if (f->zero_width < 0)
		f->zero_width = 0;
	f->width = f->width - (f->zero_width + len + 2);
	if (f->minus == 1)
		minus_pointer(f, itoa_base, len);
	else if (f->minus == 0 && f->zero == 0)
		nflag_pointer(f, itoa_base, len);
	else if (f->zero == 1)
		zero_pointer(f, itoa_base, len);
	free(itoa_base);
}
