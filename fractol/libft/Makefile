# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 20:28:46 by gperez            #+#    #+#              #
#    Updated: 2018/02/26 14:57:57 by gperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

TEST = test

SRC =	src/ft_memset.c \
		src/ft_memcpy.c \
		src/ft_memccpy.c \
		src/ft_memmove.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memalloc.c \
		src/ft_memdel.c \
		src/ft_bzero.c \
		src/ft_putchar.c \
		src/ft_putstr.c \
		src/ft_putendl.c \
		src/ft_puttab_s.c \
		src/ft_puttab_int.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_strclr.c \
		src/ft_strlen.c \
		src/ft_putnbr.c \
		src/ft_putnbr_fd.c \
		src/ft_swap.c \
		src/ft_pow.c \
		src/ft_sqrt.c \
		src/ft_isalpha.c \
		src/ft_isdigit.c \
		src/ft_isalnum.c \
		src/ft_isascii.c \
		src/ft_isprint.c \
		src/ft_strcmp.c \
		src/ft_strncmp.c \
		src/ft_strequ.c \
		src/ft_strnequ.c \
		src/ft_toupper.c \
		src/ft_str_toupper.c \
		src/ft_tolower.c \
		src/ft_str_tolower.c \
		src/ft_atoi.c \
		src/ft_strstr.c \
		src/ft_strnstr.c \
		src/ft_strnew.c \
		src/ft_strdel.c \
		src/ft_striter.c \
		src/ft_striteri.c \
		src/ft_strmap.c \
		src/ft_strmapi.c \
		src/ft_strdup.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strsub.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_strsplit.c \
		src/ft_strcat.c \
		src/ft_strncat.c \
		src/ft_strlcat.c \
		src/ft_strcpy.c \
		src/ft_strncpy.c \
		src/ft_itoa.c \
		src/ft_lstdisplay.c \
		src/ft_lstmdisplay.c \
		src/ft_lstnew.c \
		src/ft_lstdelone.c \
		src/ft_lstdel.c \
		src/ft_lstadd.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c \
		src/get_next_line.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^

%.o : %.c
	@gcc $(FLAG) -o $@ -c $<

test : fclean  $(NAME)
	@gcc $(NAME) main_libft.c -o $(TEST)

clean :
	@/bin/rm -rf src/*.o

fclean : clean
	@/bin/rm -rf $(NAME) $(TEST)

re : fclean all
