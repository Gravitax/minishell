/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:01:11 by maboye            #+#    #+#             */
/*   Updated: 2019/03/19 19:50:09 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wordcount(const char *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str && str[i] == c)
			i++;
		if (str && str[i] != c && str[i] != '\0')
			count++;
		while (str && str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}
