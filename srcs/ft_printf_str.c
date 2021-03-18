/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:49:44 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 04:57:42 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	str_minus(char *str, int len, t_struct *f)
{
	if (f->dot == 1)
	{
		if (f->precision < len)
			len = f->precision;
	}
	f->width = f->width - len;
	if (str == NULL)
		f->compteur = f->compteur + ft_putwstr("(null)", len);
	else
		f->compteur = f->compteur + ft_putwstr(str, len);
	ft_printf_width(f);
}

void	str_zero(char *str, int len, t_struct *f)
{
	if (f->dot == 1)
	{
		if (f->precision < len)
			len = f->precision;
	}
	f->width = f->width - len;
	while (f->width > 0)
	{
		ft_putchar('0');
		f->compteur++;
		f->width--;
	}
	if (str == NULL)
		f->compteur = f->compteur + ft_putwstr("(null)", len);
	else
		f->compteur = f->compteur + ft_putwstr(str, len);
}

void	str_nflag(char *str, int len, t_struct *f)
{
	if (f->dot == 1)
	{
		if (f->precision < len)
			len = f->precision;
	}
	f->width = f->width - len;
	ft_printf_width(f);
	if (str == NULL)
		f->compteur = f->compteur + ft_putwstr("(null)", len);
	else
		f->compteur = f->compteur + ft_putwstr(str, len);
}

void	ft_printf_str(va_list *args, t_struct *f)
{
	char	*str;
	int		len;

	str = va_arg(*args, char*);
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	if (f->minus == 1)
		str_minus(str, len, f);
	else if (f->minus == 0 && f->zero == 0)
		str_nflag(str, len, f);
	else if (f->zero == 1)
		str_zero(str, len, f);
}
