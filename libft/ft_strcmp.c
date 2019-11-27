/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:23 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:55:00 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int	x;

	x = 0;
	while (s1 && s2 && s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
