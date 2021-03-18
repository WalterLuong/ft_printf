/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:58:12 by wluong            #+#    #+#             */
/*   Updated: 2020/11/10 22:21:04 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parsing_flags(const char *input, t_struct *f)
{
	while (input[f->i] == '-' || input[f->i] == '0')
	{
		if (input[f->i] == '-')
			f->minus = 1;
		if (input[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
}

void	parsing_width(const char *input, t_struct *f, va_list *args)
{
	if (input[f->i] == '*')
	{
		f->width = va_arg(*args, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width *= -1;
		}
		f->i++;
	}
	else if (ft_isdigit(input[f->i]) == 1)
	{
		f->width = ft_atoi(&input[f->i]);
		while (ft_isdigit(input[f->i]) == 1)
			f->i++;
	}
}

void	parsing_dot(const char *input, t_struct *f, va_list *args)
{
	if (input[f->i] == '.')
	{
		f->dot = 1;
		f->i++;
	}
	if (input[f->i] == '*')
	{
		f->precision = va_arg(*args, int);
		if (f->precision < 0)
		{
			f->dot = 0;
			f->precision = 0;
		}
		f->i++;
	}
	else if (ft_isdigit(input[f->i]) == 1)
	{
		f->precision = ft_atoi(&input[f->i]);
		while (ft_isdigit(input[f->i]) == 1)
			f->i++;
	}
}

void	parsing(const char *input, t_struct *f, va_list *args)
{
	parsing_flags(input, f);
	parsing_width(input, f, args);
	parsing_dot(input, f, args);
}
