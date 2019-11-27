/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:48:58 by maboye            #+#    #+#             */
/*   Updated: 2019/03/13 01:36:55 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (malloc(new_size));
	if (!(new = ft_memalloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, new_size);
	free(ptr);
	return (new);
}
