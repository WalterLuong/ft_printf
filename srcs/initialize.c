/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:43:55 by wluong            #+#    #+#             */
/*   Updated: 2020/11/10 21:56:30 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*parsing_init(t_struct *f)
{
	if ((f = (t_struct*)ft_memalloc(sizeof(t_struct))) == NULL)
		return (NULL);
	f->i = 0;
	f->compteur = 0;
	return (f);
}

void		re_init(t_struct *f)
{
	f->type = 0;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
	f->zero_width = 0;
}
