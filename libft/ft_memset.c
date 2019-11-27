/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:14 by maboye            #+#    #+#             */
/*   Updated: 2019/02/27 21:34:42 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	*ptr;
	size_t	delim;
	size_t	a;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = sizeof(size_t);
	delim = n / (len == 0 ? 1 : len);
	a = c;
	ptr = (size_t *)s;
	i = -1;
	while (++i < len - 1)
	{
		a <<= 8;
		a |= c;
	}
	i = -1;
	while (++i < delim)
		ptr[i] = a;
	i *= len;
	while (i < n)
		((unsigned char*)ptr)[i++] = c;
	return (s);
}
