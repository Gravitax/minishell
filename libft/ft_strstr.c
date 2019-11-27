/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:50 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:53:06 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int	x;
	int	y;

	x = 0;
	if (!ft_strlen(to_find))
		return ((char*)str);
	while (str && str[x])
	{
		if (to_find[0] == str[x])
		{
			y = 1;
			while (to_find[y] && to_find[y] == str[x + y])
				y++;
			if (to_find[y] == '\0')
				return ((char*)&str[x]);
		}
		x++;
	}
	return (NULL);
}
