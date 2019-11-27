/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:18 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:56:39 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!dest || !src)
		return (NULL);
	while (dest && dest[x])
		x++;
	while (src && dest && src[y])
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}
