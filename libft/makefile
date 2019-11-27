# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboye <maboye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:17:40 by maboye            #+#    #+#              #
#    Updated: 2019/03/18 19:28:07 by maboye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HEADER	=	libft.h

SRC		=	ft_atoi.c\
			ft_bzero.c\
			ft_bubblesort.c\
			ft_intlen.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_ishexa.c\
			ft_islower.c\
			ft_isop.c\
			ft_isprime.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_isupper.c\
			ft_isxdigit.c\
			ft_itoa.c\
			ft_lstaddback.c\
			ft_lstaddelem.c\
			ft_lstat.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmerge.c\
			ft_lstpushback.c\
			ft_lstpushfront.c\
			ft_lstpushparams.c\
			ft_lstsize.c\
			ft_lstsort.c\
			ft_memalloc.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_power.c\
			ft_print_hex.c\
			ft_printf.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_quicksort.c\
			ft_readfile.c\
			ft_realloc.c\
			ft_sqrt.c\
			ft_strcat.c\
			ft_strcdup.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_strfjoin.c\
			ft_striter.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strndup.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnlen.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_swap.c\
			ft_tabfree.c\
			ft_tablen.c\
			ft_tabprint.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_wordcount.c\
			get_next_line.c

OBJ 	=	$(SRC:.c=.o)

CC		=	@clang

CFLAGS	=	-Wall -Wextra -Werror -I .

all:		$(NAME)

$(OBJ):		$(HEADER)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:
			@/bin/rm -rf $(OBJ)

fclean:		clean
			@/bin/rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
