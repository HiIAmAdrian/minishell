# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 16:21:12 by adstan            #+#    #+#              #
#    Updated: 2018/02/25 18:42:34 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =  bin_commands.c \
	   cd.c \
	   display.c \
	   echo.c \
	   exec_commands.c \
	   exit_unsetenv.c \
	   main.c \
	   reading.c \
	   set_env.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@make -C libft
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@gcc $(OBJ) -o $(NAME) -L ./libft -lft

all: $(NAME)

clean:
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all




