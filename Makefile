# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 15:48:03 by kdouveno          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/06/12 10:34:13 by gperez           ###   ########.fr        #
=======
#    Updated: 2018/06/11 15:23:53 by kdouveno         ###   ########.fr        #
>>>>>>> parser
#                                                                              #
# **************************************************************************** #

NAME = wolf

CC = clang
FLAGS = -Wall -Wextra -Werror

SRC_DIR =	src/
SRC_LIST =	main.c\
			parser.c \
			ft_parse_line.c\
			ft_test.c\
			walls.c\
			peer.c\
			algo.c \
			scan.c \
			equation.c \
			keys.c \

OBJS = $(SRC_LIST:.c=.o)
SRCS = $(addprefix $(SRC_DIR),$(SRC_LIST))

FM_LIST =	OpenGl\
			AppKit

FM = $(addprefix -framework ,$(FM_LIST))

INCDIR = -Ilibft/includes -Iincludes

all: $(NAME)

BLUE = \033[38;5;117m
RED = \033[38;5;203m
GREEN = \033[38;5;120m
MAGENTA = \033[38;5;135m
WHITE = \033[37m

$(NAME): $(OBJS) libft/*.c libft/includes/libft.h
	@make -C libft
	@$(CC) $(FLAGS) $(FM) libmlx.a libft/libft.a $(OBJS) -o $@
	@printf "$(MAGENTA)%15s : $(GREEN)succesfuly made!%20.0d$(WHITE)\n" $(NAME) 0

pain: $(OBJS) libft/*.c libft/includes/libft.h
	@make -C libft
	@$(CC) $(FLAGS) libmlx.a libft/libft.a $(OBJS) -o $@
	@printf "$(MAGENTA)%15s : $(GREEN)succesfuly made!%20.0d$(WHITE)\n" $(NAME) 0

%.o: $(SRC_DIR)%.c includes/wolf3d.h
	@printf "$(MAGENTA)%15s : $(BLUE)%-20s$(WHITE) ... \r" $(NAME) $(<F)
	@gcc $(FLAGS) $(INCDIR) -c $<
	@printf "$(MAGENTA)%15s : $(BLUE)%-20s$(GREEN) done $(WHITE)\n" $(NAME) $(<F)

clean:
	@make -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

test:
	printf "$(GREEN)sauce$(WHITE)\n"
	printf "\127"

re: fclean all
