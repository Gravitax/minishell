/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:12:25 by maboye            #+#    #+#             */
/*   Updated: 2019/03/21 00:15:17 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_builtins(char **stock)
{
	if (!stock || !*stock)
		return (0);
	if (!ft_strcmp(stock[0], "cd") || !ft_strcmp(stock[0], "echo"))
		return (1);
	else if (!ft_strcmp(stock[0], "setenv")
			|| !ft_strcmp(stock[0], "unsetenv")
			|| !ft_strcmp(stock[0], "env"))
		return (1);
	else
		return (0);
}

char			**ft_realloc_envp(char **envp, size_t size,
				char **stock, int choose)
{
	char	**ret;
	int		i;
	int		y;

	if (!(ret = (char**)malloc(sizeof(char*) * ++size)))
		return (envp);
	i = -1;
	y = -1;
	while (envp && envp[++i])
	{
		if (choose && !ft_strncmp(stock[1], envp[i], ft_strlen(stock[1])))
			continue ;
		if (!(ret[++y] = ft_strdup(envp[i])))
		{
			ft_tabfree((void**)ret);
			return (envp);
		}
	}
	ft_tabfree((void**)envp);
	while (++y < (int)size)
		ret[y] = NULL;
	return (ret);
}

static char		**ft_setenv_helper(char **stock, char **envp)
{
	int		i;
	int		len;

	i = -1;
	while (stock[1] && stock[1][++i])
		if (stock[1][i] == '=' && i)
		{
			len = ft_tablen((void**)envp);
			if (!(envp = ft_realloc_envp(envp, ++len, stock, 0)))
				return (envp);
			envp[len - 1] = ft_strdup(stock[1]);
			break ;
		}
	return (envp);
}

char			**ft_setenv(char **stock, char **envp)
{
	int		i;
	int		len;
	int		count;

	count = 0;
	i = -1;
	while (envp && envp[++i])
	{
		len = -1;
		while (envp[i] && envp[i][++len] && envp[i][len] != '=')
			;
		if (!ft_strncmp(stock[1], envp[i], len + 1))
		{
			ft_strdel(&envp[i]);
			if (!(envp[i] = ft_strdup(stock[1])))
				return (envp);
			count++;
			break ;
		}
	}
	if (!count)
		envp = ft_setenv_helper(stock, envp);
	return (envp);
}

char			**ft_unsetenv(char **stock, char **envp)
{
	int		i;
	int		len;

	if (!stock || !stock[1] || stock[2])
	{
		ft_putendl("usage: [ unsetenv ] [ VAR_NAME= ]");
		return (envp);
	}
	len = ft_strlen(stock[1]);
	i = 0;
	while (stock && stock[1] && stock[1][i] && stock[1][i] != '=')
		i++;
	if (i != len - 1)
	{
		ft_putendl("usage: [ unsetenv ] [ VAR_NAME= ]");
		return (envp);
	}
	i = -1;
	while (envp && envp[++i])
		if (!ft_strncmp(stock[1], envp[i], len))
		{
			envp = ft_realloc_envp(envp, ft_tablen((void**)envp) - 1, stock, 1);
			break ;
		}
	return (envp);
}
