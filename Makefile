# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/05/25 12:08:37 by noahalexand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
OFLAGS	:= -Werror -Wextra -Wall -g

NAME	:= pipex

SRCS	:=	srcs/cmd.c \
			srcs/main.c \
			srcs/path.c \
			srcs/files.c \

OBJS	:= $(SRCS:.c=.o)

LIBS	:=	srcs/libft/libft.a \
			srcs/printf/printf.a \
			srcs/get_next_line/get_next_line.a \

RM		:= rm -rf
AR		:= ar rcs

GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

TEST	:= 300

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[K[Compiling objects... "$(YELLOW)"<$<>"$(GREEN)" ] ⏳"$(RESET)
	@$(CC) $(OFLAGS) -c $< -o $(<:.c=.o)

update:
	@git pull

usage:
	@printf "\nNow you can run:\n\t./$(NAME) <file1> <cmd> ... <cmd> <file2>\n\n"

$(NAME): update $(OBJS)
	@printf $(GREEN)"\r\033[KObjects compiled succesfully ✅\n"$(RESET)
	@make -C srcs/libft
	@make -C srcs/printf
	@make -C srcs/get_next_line
	@printf $(CYAN)"\r\033[K[Compiling '$(NAME)'...] ⏳"$(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include/ -o $(NAME)
	@printf $(GREEN)"\r\033[KSuccess compiling '$(NAME)' ✅\n"$(RESET)

visualizer: $(NAME)
	@printf $(GREEN)"\r\033[KLaunching python visualizer... ⏳"$(RESET)
	@python3 pyviz.py `ruby -e "puts (1..$(TEST)).to_a.shuffle.join(' ')"`
	@printf $(GREEN)"\r\033[KPython visualizer launched succesfully ✅\n"$(RESET)

all: $(NAME) usage

load:
	@printf '\r █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r █████▒▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ██████▒▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ███████▒▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ████████▒▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r █████████▒▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ██████████▒▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ███████████▒▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ████████████▒▒▒▒▒▒\r'
	@sleep .1
	@printf '\r █████████████▒▒▒▒▒\r'
	@sleep .1
	@printf '\r ██████████████▒▒▒▒\r'
	@sleep .1
	@printf '\r ███████████████▒▒▒\r'
	@sleep .1
	@printf '\r ████████████████▒▒\r'
	@sleep .1
	@printf '\r █████████████████▒\r'
	@sleep .1
	@printf '\r ██████████████████\r'
	@sleep .1

clean:
	@printf $(CYAN)"\r\033[K[Erasing objects...] ⏳"$(RESET)
	@$(RM) $(OBJS)
	@make -C srcs/libft fclean
	@make -C srcs/printf fclean
	@make -C srcs/get_next_line fclean
	@printf $(GREEN)"\r\033[Kcleaned 🗑\n"$(RESET)

fclean:
	@printf $(CYAN)"\r\033[K[Erasing objects...] ⏳"$(RESET)
	@$(RM) $(OBJS)
	@make -C srcs/libft fclean
	@make -C srcs/printf fclean
	@make -C srcs/get_next_line fclean
	@printf $(CYAN)"\r\033[K[Erasing binary file...] ⏳"$(RESET)
	@$(RM) $(NAME) test_parser
	@printf $(GREEN)"\r\033[KForce cleaned 🗑\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re
