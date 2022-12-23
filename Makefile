# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 02:03:10 by noalexan          #+#    #+#              #
#    Updated: 2022/12/23 04:27:02 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Werror -Wextra -Wall

SRC=main.c utils.c
OBJ=$(SRC:.c=.o)

NAME=pipex

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) libft/libft.a $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	make -C libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
