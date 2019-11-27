/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:22:00 by maboye            #+#    #+#             */
/*   Updated: 2019/03/20 18:58:25 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_cd_finisher(char **stock, char ***envp, char ***home)
{
	char		path[BUFF_SIZE + 1];
	char		**pwd;
	struct stat	elem;

	if (!(getcwd(path, BUFF_SIZE)))
	{
		if (*home && **home)
			ft_strcpy(path, *home[0]);
		if (lstat(path, &elem))
			ft_strcpy(path, "/");
	}
	if (!(pwd = (char**)malloc(sizeof(char*) * 3)))
	{
		ft_tabfree((void**)*home);
		return (stock);
	}
	pwd[0] = ft_strdup("setenv");
	pwd[1] = ft_strjoin("PWD=", path);
	pwd[2] = NULL;
	*envp = ft_setenv(pwd, *envp);
	ft_tabfree((void**)pwd);
	ft_tabfree((void**)*home);
	return (stock);
}

static char		**ft_cd_helper(char **stock, char ***envp, char ***home)
{
	char	path[BUFF_SIZE + 1];
	char	**old_pwd;
	char	**pwd;
	int		ret;

	ret = 0;
	!(getcwd(path, BUFF_SIZE)) ? ft_strcpy(path, "/") : 0;
	if (stock[1] && ft_strcmp(stock[1], "-"))
		ret = chdir(stock[1]);
	ret == -1 ? ft_putendl_fd("error chdir bad access", 2) : 0;
	if (!(old_pwd = (char**)malloc(sizeof(char*) * 3)))
		ret = -2;
	ret == -1 ? free((void**)old_pwd) : 0;
	ret <= -1 ? ft_tabfree((void**)*home) : 0;
	if (ret <= -1)
		return (stock);
	pwd = ft_getenvp_value(*envp, "PWD");
	old_pwd[0] = ft_strdup("setenv");
	old_pwd[1] = ft_strfjoin("OLDPWD=",
		pwd && *pwd ? ft_strdup(pwd[0]) : ft_strdup(path), 2);
	old_pwd[2] = NULL;
	*envp = ft_setenv(old_pwd, *envp);
	ft_tabfree((void**)old_pwd);
	ft_tabfree((void**)pwd);
	return (ft_cd_finisher(stock, envp, home));
}

static char		**ft_cd(char **stock, char ***envp)
{
	char	**home;
	char	**old_pwd;
	int		ret;

	ret = 0;
	home = ft_getenvp_value(*envp, "HOME");
	if (!stock[1] || !ft_strcmp(stock[1], "--") || !ft_strcmp(stock[1], "~"))
	{
		stock = ft_realloc_envp(stock, 2, NULL, 0);
		stock[1] ? ft_strdel(&stock[1]) : 0;
		if (home && ft_strlen(*home))
			stock[1] = ft_strdup(home[0]);
		else
		{
			ft_putendl("no HOME variable set");
			return (stock);
		}
	}
	old_pwd = ft_getenvp_value(*envp, "OLDPWD");
	if (old_pwd && !ft_strcmp(stock[1], "-"))
		ret = chdir(old_pwd[0]);
	ret == -1 ? ft_putendl_fd("error chdir bad access", 2) : 0;
	ret == -1 ? ft_tabfree((void**)home) : 0;
	ft_tabfree((void**)old_pwd);
	return (ret == -1 ? stock : ft_cd_helper(stock, envp, &home));
}

static char		**ft_builtins_helper(char ***stock, char **envp, int len)
{
	if (!ft_strcmp(*stock[0], "cd"))
	{
		if (len >= 3)
			ft_putendl("usage: [ cd ] [ directory ]");
		else
			*stock = ft_cd(*stock, &envp);
	}
	else if (!ft_strcmp(*stock[0], "echo"))
	{
		if (len == 1)
			ft_putendl("usage: [ echo ] [ -n ] [ string ... ]");
		else
			ft_echo(*stock);
	}
	return (envp);
}

char			**ft_builtins_handler(char ***stock, char **envp)
{
	int	len;

	if (!stock || !*stock || !**stock)
		return (envp);
	len = ft_tablen((void**)*stock);
	if (!ft_strcmp(*stock[0], "env"))
	{
		if (len > 1)
			ft_putendl("usage: [ env ]");
		else if (len == 1 && envp)
			ft_tabprint(envp);
	}
	else if (!ft_strcmp(*stock[0], "setenv"))
	{
		if (len == 1 || len > 2)
			ft_putendl("usage: [ setenv ] [ VAR_NAME=content:... ]");
		else
			envp = ft_setenv(*stock, envp);
	}
	else if (!ft_strcmp(*stock[0], "unsetenv"))
	{
		envp = ft_unsetenv(*stock, envp);
	}
	return (ft_builtins_helper(stock, envp, len));
}
