# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboye <maboye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 15:11:15 by maboye            #+#    #+#              #
#    Updated: 2019/03/20 16:55:24 by maboye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

HEADER	=	minishell.h

SRC		=	builtins.c \
			environment.c \
			envp_builtins.c \
			ft_splitwspc.c \
			minishell.c \
			utils.c \
			main.c

OBJ 	=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-g -Wall -Wextra -Werror -I . -g3
#-fsanitize=address

PURPLE	=	\033[38;5;105m
BLUE	=	\033[38;5;141m
END		=	\033[0m

all:		$(NAME)

lib:
			@$(MAKE) -C libft/
			@echo "${BLUE}[LIBRARY COMPILED]${END}"

$(OBJ):		$(HEADER)

$(NAME):	lib $(OBJ)
			@$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
			@echo "${PURPLE}[$(NAME) COMPILED]${END}"
clean:
			@/bin/rm -rf $(OBJ)
			@$(MAKE) -C libft/ clean
			@echo "${BLUE}[.o deleted]${END}"

fclean:		clean
			@/bin/rm -rf $(NAME)
			@$(MAKE) -C libft/ fclean
			@echo "${BLUE}[$(NAME) deleted]${END}"

re:			fclean all

rebuild:	$(OBJ)
			@$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
			@echo "${PURPLE}[$(NAME) COMPILED]${END}"

jeez:
			@/bin/rm -rf $(OBJ)
			@echo "${BLUE}[workspace cleaned]${END}"

.PHONY:		all lib clean fclean re rebuild jeez
