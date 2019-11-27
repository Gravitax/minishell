/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:37:59 by maboye            #+#    #+#             */
/*   Updated: 2019/03/21 00:14:15 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_doll_helper(char **stock, char **var, char *tmp, int len)
{
	int	i;
	int	y;

	y = 0;
	while (tmp && len - 1 > 0 && !ft_isalnum(tmp[len - 1]))
	{
		y++;
		len--;
	}
	*stock = ft_strfjoin(*stock, ft_strsub(tmp, len - 1, y), 3);
	i = 1;
	while (var && var[i])
		*stock = ft_strfjoin(ft_strfjoin(*stock, ":", 1), var[i++], 1);
	*stock = ft_strfjoin(*stock,
		ft_strsub(tmp, len, ft_strlen(tmp) - len), 3);
}

static int		ft_doll_checker(char **stock, char **envp, int y, int len)
{
	char	**var;
	char	*tmp;
	char	*save;

	tmp = ft_strdup(*stock);
	ft_strdel(stock);
	if (!tmp || !(save = ft_strsub(tmp, y, len - y)))
	{
		tmp ? ft_strdel(&tmp) : 0;
		return (0);
	}
	while (tmp && len - 1 - y > 0 && !ft_isalnum(tmp[len - 1]))
		save[len-- - 1 - y] = 0;
	if ((var = ft_getenvp_value(envp, save + 1)))
	{
		*stock = ft_strfjoin(ft_strsub(tmp, 0, y), var[0], 1);
		ft_doll_helper(stock, var, tmp, len);
	}
	else
		*stock = ft_strfjoin(ft_strsub(tmp, 0, y),
			ft_strsub(tmp, len, ft_strlen(tmp) - len), 3);
	ft_strdel(&tmp);
	ft_strdel(&save);
	ft_tabfree((void**)var);
	return ((int)ft_strlen(*stock));
}

char			**ft_handle_doll(char **stock, char **envp)
{
	int		i;
	int		y;
	int		len;

	i = -1;
	while (stock && stock[++i])
	{
		len = ft_strlen(stock[i]);
		y = -1;
		while (++y < len)
			if (y + 1 < len && stock[i] && stock[i][y] == '$')
			{
				if (y + 1 < len && stock[i]
				&& stock[i][y] && stock[i][y + 1] == '$')
					continue ;
				len = y + 1;
				while (stock && stock[i] && stock[i][len]
				&& stock[i][len] != '$')
					len++;
				len = ft_doll_checker(&stock[i], envp, y--, len);
			}
	}
	return (stock);
}

void			ft_signal_handler(int sig)
{
	signal(sig, ft_signal_handler);
	write(1, "\n", 1);
	ft_prompt();
}

void			ft_signal_handler2(int sig)
{
	signal(sig, ft_signal_handler);
	write(1, "\n", 1);
}
