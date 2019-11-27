/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:06:43 by maboye            #+#    #+#             */
/*   Updated: 2019/03/20 23:52:35 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_fork_party(char *file, char **stock, char **envp)
{
	struct stat	elem;
	pid_t		father;

	if (file && stock && !lstat(file, &elem))
	{
		if ((father = fork()) == 0)
		{
			if (execve(file, stock, envp) == -1)
				ft_putendl_fd("not an executable", 2);
		}
		else if (father > 0)
		{
			signal(SIGINT, ft_signal_handler2);
			wait(NULL);
		}
		else
			ft_putendl_fd("fork error", 2);
		return (1);
	}
	return (0);
}

static int		ft_dothefork(char *file, char **stock, char **envp)
{
	struct stat	elem;
	pid_t		father;

	if (stock && !lstat(stock[0], &elem))
	{
		if ((father = fork()) == 0)
		{
			if (execve(stock[0], stock, envp) == -1)
				ft_putendl_fd("not an executable", 2);
		}
		else if (father > 0)
		{
			signal(SIGINT, ft_signal_handler2);
			wait(NULL);
		}
		else
			ft_putendl_fd("fork error", 2);
		return (1);
	}
	return (ft_fork_party(file, stock, envp));
}

static void		ft_commands_handler(char ***stock, char ***envp, char **path)
{
	int			i;
	int			count;
	char		*file;

	file = NULL;
	count = 0;
	if (*stock && ft_check_builtins(*stock))
	{
		*envp = ft_builtins_handler(stock, *envp);
		return ;
	}
	if (!(path = ft_getenvp_value(*envp, "PATH")) || (path && !*path))
		count = ft_dothefork(file, *stock, *envp);
	i = -1;
	while (path && path[++i])
	{
		file = ft_strfjoin(ft_strjoin(path[i], "/"), *stock[0], 1);
		count = ft_dothefork(file, *stock, *envp);
		ft_strdel(&file);
		if (count)
			break ;
	}
	if (!count)
		ft_printf("minishell: command not found: %s\n", *stock[0]);
	ft_tabfree((void**)path);
}

static int		ft_exit(char *buffer)
{
	int		i;

	i = -1;
	while (buffer && buffer[++i] && ft_isspace(buffer[i]))
		;
	if (!ft_strncmp("exit", buffer + i, 4))
		return (ft_isalnum(buffer[i + 4]));
	return (1);
}

int				minishell(char **buffer, char ***stock,
				char **env, char ***envp)
{
	int		i;

	signal(SIGINT, ft_signal_handler);
	ft_prompt();
	if (get_next_line(0, buffer) <= 0)
		return (0);
	if (*buffer && !ft_exit(*buffer))
		return (0);
	if (!(*envp = ft_environment_handler(env, *envp)))
		return (0);
	stock = ft_command_maker(*buffer);
	if (stock)
	{
		i = -1;
		while (stock && stock[++i])
		{
			stock[i] = ft_handle_tilde(stock[i], *envp);
			ft_handle_doll(stock[i], *envp);
			ft_commands_handler(&stock[i], envp, NULL);
			ft_tabfree((void**)stock[i]);
		}
		free(stock);
	}
	return (1);
}
