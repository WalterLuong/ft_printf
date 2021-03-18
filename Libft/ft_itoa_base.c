/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:23:29 by wluong            #+#    #+#             */
/*   Updated: 2020/11/10 22:32:02 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_itoa_base(char *str, long int nb, int len, char *base)
{
	int len_base;

	len_base = ft_strlen(base);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[len - 1] = base[nb % len_base];
		nb = nb / len_base;
		len--;
	}
	return (str);
}

char	*ft_itoa_base(long int nbr, char *base)
{
	long int	nb;
	char		*str;
	int			len;
	int			len_base;

	nb = nbr;
	len = 0;
	len_base = ft_strlen(base);
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / len_base;
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	return (fill_itoa_base(str, nb, len, base));
}
