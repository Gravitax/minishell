/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:10:05 by maboye            #+#    #+#             */
/*   Updated: 2019/03/20 23:25:41 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_prompt(void)
{
	char	stock[BUFF_SIZE + 1];
	char	*path;
	int		i;

	getcwd(stock, BUFF_SIZE);
	i = ft_strlen(stock);
	while (stock[--i] && stock[i] != '/')
		;
	if (!(path = ft_strdup(stock + i + 1)))
		ft_putstr("prompt_error: ");
	if (path)
	{
		ft_printf("\033[38;5;105m%s:\033[0m ", path);
		ft_strdel(&path);
	}
}

char			**ft_handle_tilde(char **stock, char **envp)
{
	int		i;
	char	**tmp;
	char	*tmp2;

	if ((tmp = ft_getenvp_value(envp, "HOME")))
	{
		i = -1;
		while (stock && stock[++i])
		{
			if (!ft_strncmp(stock[i], "~", 1))
			{
				tmp2 = ft_strdup(stock[i] + 1);
				ft_strdel(&stock[i]);
				stock[i] = ft_strfjoin(tmp[0], tmp2, 2);
			}
			else if (!ft_strcmp("~", stock[i]))
			{
				ft_strdel(&stock[i]);
				stock[i] = ft_strdup(tmp[0]);
			}
			(stock[i] && !*stock[i]) ? ft_strdel(&stock[i]) : 0;
		}
		ft_tabfree((void**)tmp);
	}
	return (stock);
}

static char		***ft_multicast(char *buffer, char ***ret)
{
	int		i;
	int		y;
	int		count;
	char	*tmp;

	tmp = NULL;
	y = 0;
	count = 0;
	i = -1;
	while (buffer && buffer[++i])
	{
		if (buffer[i] == ';')
		{
			tmp = ft_strsub(buffer, y, i - y);
			y = i + 1;
		}
		else if (i == (int)ft_strlen(buffer) - 1)
			tmp = ft_strsub(buffer, y, (int)ft_strlen(buffer) - y);
		tmp ? ret[count++] = ft_splitwspc(tmp) : 0;
		tmp ? ft_strdel(&tmp) : 0;
	}
	ret[count] = NULL;
	return (ret);
}

char			***ft_command_maker(char *buffer)
{
	int		i;
	int		count;
	char	***ret;

	count = 1;
	i = -1;
	while (buffer && buffer[++i] && ft_isspace(buffer[i]))
		;
	if (i == (int)ft_strlen(buffer))
		return (NULL);
	i = -1;
	while (buffer && buffer[++i])
		if (buffer[i] == ';')
			count++;
	if (!(ret = (char***)malloc(sizeof(char**) * (count + 1))))
		return (NULL);
	return (ft_multicast(buffer, ret));
}

int				main(int ac, char **av, char **env)
{
	char	**envp;
	char	*buffer;

	if (!isatty(0))
	{
		ft_putendl_fd("minishell is interactive only", 2);
		return (0);
	}
	buffer = NULL;
	if (ac == 1 && !av[1])
	{
		envp = ft_environment_handler(env, NULL);
		while (42)
		{
			if (!minishell(&buffer, NULL, env, &envp))
				break ;
			ft_strdel(&buffer);
		}
		ft_strdel(&buffer);
		ft_tabfree((void**)envp);
		return (1);
	}
	ft_putendl("minishell: usage: tarnation !");
	return (0);
}
