/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:25:11 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 14:26:50 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	minus_u(t_struct *f, char *itoa_base, int len)
{
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
	ft_printf_width(f);
}

void	zero_u(t_struct *f, char *itoa_base, int len)
{
	while (f->width > 0)
	{
		ft_putchar('0');
		f->compteur++;
		f->width--;
	}
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
}

void	nflag_u(t_struct *f, char *itoa_base, int len)
{
	ft_printf_width(f);
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa_base, len);
}

void	ft_printf_unsigned(va_list *args, t_struct *f)
{
	unsigned int	nb;
	char			*itoa_base;
	int				len;

	nb = va_arg(*args, unsigned int);
	itoa_base = ft_itoa_base(nb, "0123456789");
	len = ft_strlen(itoa_base);
	if (f->dot == 1 && f->precision > 0)
		f->zero_width = f->precision - len;
	if (f->dot == 1 && f->precision <= 0 && nb == 0)
	{
		itoa_base[0] = '\0';
		f->width++;
	}
	if (f->zero_width < 0)
		f->zero_width = 0;
	f->width = f->width - (f->zero_width + len);
	if (f->minus == 1)
		minus_u(f, itoa_base, len);
	else if (f->zero == 1)
		zero_u(f, itoa_base, len);
	else if (f->minus == 0 && f->zero == 0)
		nflag_u(f, itoa_base, len);
	free(itoa_base);
}
