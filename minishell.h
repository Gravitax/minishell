/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:19:15 by maboye            #+#    #+#             */
/*   Updated: 2019/03/20 19:36:03 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <pwd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# include "libft/libft.h"

char			**ft_builtins_handler(char ***stock, char **envp);
int				ft_check_builtins(char **stock);
char			***ft_command_maker(char *buffer);
void			ft_echo(char **stock);
char			**ft_environment_handler(char **env, char **envp);
char			**ft_environment_maker(char **envp);
char			**ft_getenvp_value(char **envp, char *str);
char			**ft_handle_doll(char **stock, char **envp);
char			**ft_handle_tilde(char **stock, char **envp);
void			ft_prompt(void);
char			**ft_realloc_envp(char **envp, size_t size,
					char **stock, int choose);
char			**ft_setenv(char **stock, char **envp);
void			ft_signal_handler(int sig);
void			ft_signal_handler2(int sig);
char			**ft_splitwspc(char const *s);
char			**ft_unsetenv(char **stock, char **envp);
int				minishell(char **buffer, char ***stock,
					char **env, char ***envp);

#endif
