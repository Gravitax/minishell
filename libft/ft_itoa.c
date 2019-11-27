/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:57:04 by maboye            #+#    #+#             */
/*   Updated: 2019/02/22 04:12:10 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		x;
	long	nb;

	nb = (long)n;
	x = ft_intlen(nb) - 1;
	if (!(str = ft_strnew(x + (nb < 0 ? 2 : 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		x++;
	}
	str[x + 1] = '\0';
	while (nb >= 10)
	{
		str[x] = nb % 10 + '0';
		nb = nb / 10;
		x--;
	}
	str[x] = nb + '0';
	return (str);
}
