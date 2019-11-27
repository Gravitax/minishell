/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:09:06 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:51:36 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void **s1, void **s2)
{
	void	*stock;

	if (s1 && s2 && *s1 && *s2)
	{
		stock = *s2;
		*s2 = *s1;
		*s1 = stock;
	}
}
