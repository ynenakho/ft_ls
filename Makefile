# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 18:23:28 by ynenakho          #+#    #+#              #
#    Updated: 2018/03/19 18:26:12 by ynenakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = main.c get_opt.c sorting.c list_operations.c handle_list.c print.c \
functions.c sort_funcs.c functions2.c
OBJ = main.o get_opt.o sorting.o list_operations.o handle_list.o print.o \
functions.o sort_funcs.o functions2.o

DEPS = ft_ls.h
LIBS = ./libft/libft.a


all: libftcreate $(NAME) $(CHECKER)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(LIBS)

libftcreate:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all
