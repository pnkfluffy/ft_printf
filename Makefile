# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 10:38:32 by jfelty            #+#    #+#              #
#    Updated: 2019/11/01 19:24:27 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I .

SRC =	ft_printf.c \
		populate.c \
		format_help.c \
		format_csp.c \
		format_diou.c

OBJ = $(SRC:.c=.o)

OB = ./*.o

FT_LIB = ./src/libft/libft.a

FT_LIB_OB = ./src/libft/*.o

all: $(NAME)


$(NAME): $(OBJ) lib 
	ar rc $(NAME) $(OB) $(FT_LIB_OB)
	ranlib $(NAME)

lib:
	make -C src/libft/

test: lib
	$(CC) $(CFLAGS) $(SRC) test.c -g src/libft/libft.a -o test.out

#pflib:
#	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)
#	@echo "libftprintf.a created"
#	https://github.com/SLO42/ft_printf/blob/master/ft_printf_v2/Makefile

clean:
	rm -rf $(OBJ)
	make -C src/libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f test.out
	make -C src/libft/ fclean

re: fclean all

.PHONY: lib out clean all fclean re
