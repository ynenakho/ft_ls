# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 13:01:35 by ynenakho          #+#    #+#              #
#    Updated: 2018/02/02 02:54:19 by ynenakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = gcc 
FLAGS = -Wall -Wextra -Werror
LIBFT = ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_strrchr.c 		\
	  ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strcmp.c ft_strncat.c 		\
	  ft_strstr.c ft_bzero.c ft_isprint.c ft_memmove.c ft_strcpy.c 		\
	  ft_strncmp.c ft_tolower.c ft_isalnum.c ft_memccpy.c ft_memset.c 	\
	  ft_strdup.c ft_strncpy.c ft_toupper.c ft_isalpha.c ft_memchr.c 		\
	  ft_strcat.c ft_strlcat.c ft_strnstr.c 								\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c 		\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_putchar.c ft_putstr.c 	\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c 		\
	  ft_strtrim.c ft_putnbr.c ft_strsplit.c ft_itoa.c ft_putendl.c 		\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnlen.c	\
	  ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 	\
	  ft_lstdel.c ft_bzero_bwd.c ft_memcpy_bwd.c ft_isspace.c ft_print2d.c 	\
	  ft_print_byte.c ft_bubblesort.c ft_print_array_int.c ft_push.c ft_lstcount.c \
	  ft_lstpush.c ft_strnjoin.c ft_strmjoin.c get_next_line.c

PRINTF = conversions.c ft_printf.c functions.c handle_char.c handle_int.c handle_str.c ft_itoaf.c \
		handle_addr.c handle_hex.c handle_octal.c handle_uint.c parse_funcs.c spec_handling.c \
		ft_wcharlen.c handle_wchar.c handle_wstr.c ft_wstr_helper.c handle_binnary.c

PRINTFDIR = ./ft_printf

PRINTFSRC = $(patsubst %, $(PRINTFDIR)/%, $(PRINTF))

SRC = $(LIBFT) $(PRINTFSRC)

OBJECT = $(SRC:.c=.o)

DEPS = libft.h ./ft_printf/ft_printf.h

all: $(NAME) INDEX

INDEX:
	@ranlib $(NAME)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJECT)
	@ar rc $@ $^

clean:
	@/bin/rm -f $(OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re INDEX
