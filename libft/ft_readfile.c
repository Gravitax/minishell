/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:17:32 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:57:44 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_readfile(char *file)
{
	int		ret;
	int		x;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	if (!file || BUFF_SIZE < 0)
		return (NULL);
	if (!(str = ft_strnew(1)))
		return (NULL);
	x = open(file, O_RDONLY);
	while ((ret = read(x, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		str = ft_strfjoin(str, buf, 1);
	}
	close(x);
	return (str);
}
