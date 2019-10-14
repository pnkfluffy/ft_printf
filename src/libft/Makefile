# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 15:25:27 by jfelty            #+#    #+#              #
#    Updated: 2019/10/13 17:01:21 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#name of resultant compiled library

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I. -c
#flags to compile with header in local directory

SRC =	ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_isspace.c \
		ft_strtrim.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_numlen.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_wordcount.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c \
		ft_sortinttab.c \
		ft_get_next_line.c \
		ft_strnchr.c \
		ft_replacechr.c \
		ft_getnxtnbr.c \
		ft_atoi_base.c \
		ft_fillstrnew.c \
		ft_itoa_base.c \
		ft_power.c \
		ft_strrev.c \
		ft_ll_itoa_base.c
#all source files

OBJ = $(SRC:.c=.o)
#the .object varients of the SRC files

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "┬┴┬┴┤ ͜ʖ ͡°) ├┬┴┬┴"
#ar updates and rc replaces library file if any changes have been made
#@ suppresses command line outputs

clean:
	@rm -f $(OBJ)
#cleans object files in directory

fclean: clean
	@rm -f $(NAME)
	@echo "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ ✧ﾟ･: *ヽ(◕ヮ◕ヽ)"
#empties library as well

re: fclean all

.PHONY: clean fclean all re