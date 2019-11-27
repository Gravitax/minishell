/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:26 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:54:53 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int	x;

	if (!dest || !src)
		return (NULL);
	x = -1;
	while (src && src[++x])
		dest[x] = src[x];
	dest[x] = '\0';
	return (dest);
}
