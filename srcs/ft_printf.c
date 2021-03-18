/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:58:00 by wluong            #+#    #+#             */
/*   Updated: 2020/11/12 04:56:39 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		if_percent(va_list *args, t_struct *f, const char *input)
{
	f->i++;
	parsing(input, f, args);
	f->type = input[f->i];
	if (f->type == 0)
		return (-1);
	f->i++;
	check_error(f);
	convert_type(args, f);
	re_init(f);
	return (1);
}

void	print_input(const char *input, t_struct *f)
{
	ft_putchar(input[f->i]);
	f->i++;
	f->compteur++;
}

int		ft_printf(const char *input, ...)
{
	va_list		args;
	t_struct	*f;
	int			len;

	va_start(args, input);
	len = 0;
	f = NULL;
	f = parsing_init(f);
	while (input[f->i])
	{
		if (input[f->i] == '%')
		{
			if (if_percent(&args, f, input) < 0)
			{
				free(f);
				return (0);
			}
		}
		else if (input[f->i] != '%')
			print_input(input, f);
	}
	len = f->compteur;
	free(f);
	va_end(args);
	return (len);
}
