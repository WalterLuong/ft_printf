/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 04:27:37 by wluong            #+#    #+#             */
/*   Updated: 2020/11/11 04:26:33 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int c);
char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		ft_putchar(char c);
int			ft_putwstr(char *s, int len);
size_t		ft_strlen(char *s);
void		ft_putstr(char *s);
char		*ft_itoa_base(long int nbr, char *base);

#endif
