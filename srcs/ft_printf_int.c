/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 03:53:04 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 05:47:33 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	minus_int(t_struct *f, char *itoa, int nbr, int len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		f->compteur++;
		f->width--;
	}
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa, len);
	ft_printf_width(f);
}

void	zero_int(t_struct *f, char *itoa, int nbr, int len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		f->compteur++;
		f->width--;
	}
	while (f->width > 0)
	{
		ft_putchar('0');
		f->compteur++;
		f->width--;
	}
	f->compteur = f->compteur + ft_putwstr(itoa, len);
}

void	no_flags_int(t_struct *f, char *itoa, int nbr, int len)
{
	if (nbr < 0)
		f->width--;
	ft_printf_width(f);
	if (nbr < 0)
	{
		ft_putchar('-');
		f->compteur++;
	}
	ft_printf_zwidth(f);
	f->compteur = f->compteur + ft_putwstr(itoa, len);
}

void	ft_printf_int(va_list *args, t_struct *f)
{
	char	*itoa;
	int		nbr;
	int		len;

	nbr = va_arg(*args, int);
	itoa = ft_itoa(nbr);
	len = ft_strlen(itoa);
	if (f->dot == 1 && f->precision > 0)
		f->zero_width = f->precision - len;
	if (f->dot == 1 && f->precision <= 0 && nbr == 0)
	{
		itoa[0] = '\0';
		f->width++;
	}
	if (f->zero_width < 0)
		f->zero_width = 0;
	f->width = f->width - (f->zero_width + len);
	if (f->minus == 1)
		minus_int(f, itoa, nbr, len);
	else if (f->minus == 0 && f->zero == 0)
		no_flags_int(f, itoa, nbr, len);
	else if (f->zero == 1)
		zero_int(f, itoa, nbr, len);
	free(itoa);
}
