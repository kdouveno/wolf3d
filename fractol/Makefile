# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperez <gperez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 10:25:56 by gperez            #+#    #+#              #
#    Updated: 2018/05/25 15:05:14 by gperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Werror -Wextra -O2

LIBS = libft/libft.a

MLXI = /usr/local/include

MLXL = /usr/local/lib

GL = -framework OpenGL

APP = -framework AppKit

TEST = test_algo

SRC =	fractol.c \
		main.c \
		ft_key.c \
		ft_mouse.c \
		ft_motion_mouse.c \
		ft_draw.c \
		ft_algo.c \
		ft_module.c \
		ft_iteration.c \
		ft_interface.c \
		ft_move_image.c \
		ft_random_color.c \
		ft_thread.c \
		ft_create_thread.c \
		key/k_escape.c \
		key/k_refresh.c \
		key/k_direction.c \
		key/k_interface.c \
		key/k_color.c \
		key/k_zoom.c \
		key/k_iter.c \
		key/k_coords.c \
		key/k_lock.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBS) :
	@make -C libft

$(NAME) : $(OBJ) $(LIBS)
	@gcc $(FLAG) libmlx.a -I. -lpthread $(GL) $(APP) $^ -o $(NAME)

%.o : %.c
	@gcc $(FLAG) -o $@ -c $<

clean :
	@/bin/rm -rf libft/src/*.o
	@/bin/rm -rf key/*.o
	@/bin/rm -rf *.o

fclean : clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(TEST)
	@/bin/rm -rf $(LIBS)
	@/bin/rm -rf *.dSYM

re : fclean all
