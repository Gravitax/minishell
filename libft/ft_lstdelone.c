/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:21:06 by maboye            #+#    #+#             */
/*   Updated: 2019/03/18 19:30:01 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst)
{
	if (alst)
	{
		ft_memdel(&((*alst)->content));
		ft_memdel(&((*alst)->data));
		ft_memdel((void **)alst);
	}
}
