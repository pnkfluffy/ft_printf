# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 10:38:32 by jfelty            #+#    #+#              #
#    Updated: 2019/10/04 17:17:40 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @gcc

BUG = -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c

OBJ = $(SRC.c=.o)

all: $(NAME)

$(NAME): lib out

lib:
	make -C src/libft/
	make -C src/libft/ clean
# -C flag changes file location, so make is run in the libft directory

out:
	$(CC) $(BUG) $(CFLAGS) $(SRC) src/libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C src/libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	make -C src/libft/ fclean

re: fclean all

.PHONY: lib out clean all fclean re