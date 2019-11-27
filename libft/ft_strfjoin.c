/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:10:44 by maboye            #+#    #+#             */
/*   Updated: 2019/03/18 20:33:22 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(const char *s1, const char *s2, int len_s1, int len_s2)
{
	int		x;
	int		y;
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	x = -1;
	y = -1;
	while (s1 && s1[++x] && x < len_s1)
		tmp[x] = s1[x];
	while (s2 && s2[++y] && y < len_s2)
		tmp[x++] = s2[y];
	tmp[x] = '\0';
	return (tmp);
}

char			*ft_strfjoin(const char *s1, const char *s2, int choose)
{
	int		len_s1;
	int		len_s2;
	char	*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = ft_copy(s1, s2, len_s1, len_s2)))
		return (NULL);
	choose == 1 ? ft_strdel((char**)&s1) : 0;
	choose == 2 ? ft_strdel((char**)&s2) : 0;
	if (choose == 3)
	{
		ft_strdel((char**)&s1);
		ft_strdel((char**)&s2);
	}
	return (ret);
}
