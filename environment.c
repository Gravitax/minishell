/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:53:48 by maboye            #+#    #+#             */
/*   Updated: 2019/03/21 00:13:34 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_get_username(void)
{
	uid_t			uid;
	struct passwd	*pw;

	uid = geteuid();
	pw = getpwuid(uid);
	return (pw ? pw->pw_name : NULL);
}

void			ft_echo(char **stock)
{
	int		i;
	int		y;
	int		check;

	i = 0;
	if (ft_tablen((void**)stock) > 1)
		i = !ft_strcmp(stock[1], "-n") ? 1 : 0;
	check = i ? 1 : 0;
	while (stock && stock[++i])
	{
		y = -1;
		while (stock[i] && stock[i][++y])
			if (!(stock[i][y] == '"'))
			{
				if (check)
					if (stock[i][y] == '\n')
						stock[i][y] =
							y == (int)ft_strlen(stock[i]) - 1 ? ' ' : '\0';
				write(1, &stock[i][y], 1);
			}
		if (i == ft_tablen((void**)stock) - 1)
			check ? ft_putendl("\033[0;38;5;9m%\033[0m") : ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}

char			**ft_getenvp_value(char **envp, char *str)
{
	int		i;
	int		len;
	char	**split;

	if (!str)
		return (NULL);
	split = NULL;
	i = -1;
	while (envp && envp[++i])
	{
		len = -1;
		while (envp[i] && envp[i][++len] && envp[i][len] != '=')
			;
		if (!ft_strncmp(str, envp[i], (int)ft_strlen(str)))
			if (!ft_strncmp(str, envp[i], len))
			{
				if (!ft_strlen(envp[i] + len + 1))
					break ;
				if (!(split = ft_strsplit(envp[i] + len + 1, ':')))
					return (NULL);
				break ;
			}
	}
	return (split);
}

char			**ft_environment_maker(char **envp)
{
	char		stock[BUFF_SIZE + 1];
	char		*name;

	if (!envp || !(ft_tablen((void**)envp)))
	{
		if (!(envp = (char**)malloc(sizeof(char*) * 6)))
			return (NULL);
		if (!(getcwd(stock, BUFF_SIZE)))
			ft_strcpy(stock, "/");
		name = ft_get_username();
		envp[0] = ft_strjoin("PWD=", stock);
		envp[1] = ft_strdup("TERM=xterm-256color");
		envp[2] = ft_strjoin("USER=", name);
		envp[3] = ft_strfjoin("HOME=", ft_strjoin("/Users/", name), 2);
		envp[4] = ft_strdup("PATH=/usr/bin:/bin:/usr/sbin:/sbin");
		envp[5] = NULL;
	}
	return (envp);
}

char			**ft_environment_handler(char **env, char **envp)
{
	int		i;
	int		len;

	if (*env && (!envp || !*envp))
	{
		len = ft_tablen((void**)env);
		if (!(envp = (char**)malloc(sizeof(char*) * (len + 1))))
			return (NULL);
		i = -1;
		while (++i < len)
			if (!(envp[i] = ft_strdup(env[i])))
			{
				ft_tabfree((void**)envp);
				return (NULL);
			}
		envp[i] = NULL;
	}
	else
	{
		if (!(envp = ft_environment_maker(envp)))
			ft_tabfree((void**)envp);
	}
	return (envp);
}
