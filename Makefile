# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 10:38:32 by jfelty            #+#    #+#              #
#    Updated: 2019/10/13 17:42:05 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @gcc

#REMOVE BEFORE SUBMISSION -------------------------------------
BUG = -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I.

SRC =	ft_printf.c \
		populate.c \
		format_help.c \
		format_csp.c \
		format_diou.c

OBJ = $(SRC.c=.o)

FT_LIB = $(addprefix ./src/libft/libft.a)

FT_LIB_OB = $(addprefix $(src/libft/*.o))

all: $(NAME)

$(NAME): lib out

lib:
	make -C src/libft/
	make -C src/libft/ clean
# -C flag changes file location, so make is run in the libft directory

#pflib:
#	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)
#	@echo "libftprintf.a created"
#	https://github.com/SLO42/ft_printf/blob/master/ft_printf_v2/Makefile

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
