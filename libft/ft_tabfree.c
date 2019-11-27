/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:32:49 by maboye            #+#    #+#             */
/*   Updated: 2019/03/15 21:41:10 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tabfree(void **add)
{
	int		x;

	x = 0;
	if (add)
	{
		while (add && add[x])
			ft_memdel(&add[x++]);
		free((void**)add);
		add = NULL;
	}
}