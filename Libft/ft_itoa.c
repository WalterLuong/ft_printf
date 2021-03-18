/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:28:36 by wluong            #+#    #+#             */
/*   Updated: 2020/11/10 19:05:42 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_itoa(char *str, long int nb, int len)
{
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			len;

	nb = n;
	len = 0;
	if (n < 0)
		nb = -n;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	return (fill_itoa(str, nb, len));
}
