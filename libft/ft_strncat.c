/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:37 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:53:41 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(dest);
	y = 0;
	while (src && src[y] && (y < nb))
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}
