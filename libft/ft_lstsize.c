/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:28:53 by maboye            #+#    #+#             */
/*   Updated: 2019/03/16 02:34:27 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *source)
{
	int		count;
	t_list	*begin;

	count = 1;
	if (!source)
		return (0);
	begin = source;
	while (begin->next)
	{
		count++;
		begin = begin->next;
	}
	return (count);
}
