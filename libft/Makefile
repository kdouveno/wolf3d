# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 15:48:03 by kdouveno          #+#    #+#              #
#    Updated: 2018/05/25 18:24:59 by gperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror



SRCS = ft_atoi.c\
  ft_bzero.c\
  ft_isalnum.c\
  ft_isalpha.c\
  ft_isascii.c\
  ft_isdigit.c\
  ft_islower.c\
  ft_isprint.c\
  ft_isupper.c\
  ft_itoa.c\
  ft_lstadd.c\
  ft_lstdel.c\
  ft_lstdelone.c\
  ft_lstiter.c\
  ft_lstmap.c\
  ft_lstnew.c\
  ft_lstrev.c\
  ft_memalloc.c\
  ft_memccpy.c\
  ft_memchr.c\
  ft_memcmp.c\
  ft_memcpy.c\
  ft_memdel.c\
  ft_memmove.c\
  ft_memset.c\
  ft_putchar.c\
  ft_putchar_fd.c\
  ft_putendl.c\
  ft_putendl_fd.c\
  ft_putnbr.c\
  ft_putnbr_fd.c\
  ft_putstr.c\
  ft_putstr_fd.c\
  ft_puttab_s.c \
  ft_strcat.c\
  ft_strchr.c\
  ft_strclr.c\
  ft_strcmp.c\
  ft_strcpy.c\
  ft_strdel.c\
  ft_strdup.c\
  ft_strequ.c\
  ft_striter.c\
  ft_striteri.c\
  ft_strjoin.c\
  ft_strlcat.c\
  ft_strlen.c\
  ft_strmap.c\
  ft_strmapi.c\
  ft_strncat.c\
  ft_strncmp.c\
  ft_strncpy.c\
  ft_strnequ.c\
  ft_strnew.c\
  ft_strnstr.c\
  ft_strrchr.c\
  ft_strsplit.c\
  ft_free_tab.c\
  ft_strstr.c\
  ft_strsub.c\
  ft_strtrim.c\
  ft_tolower.c\
  ft_toupper.c\
  ft_sqrt.c\
  get_next_line.c\
  ft_atod.c

OBJS = $(SRCS:.c=.o)

BLUE = \033[38;5;117m
RED = \033[38;5;203m
GREEN = \033[38;5;120m
MAGENTA = \033[38;5;135m
WHITE = \033[37m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@printf "$(MAGENTA)%15s : $(GREEN)succesfuly made! %10.0d\n" $(NAME) 0

%.o: %.c
	@printf "$(MAGENTA)%15s : $(BLUE)%-20s$(WHITE) ...\r" $(NAME) $(<F)
	@gcc $(FLAGS) -I includes -c $^
	@printf "$(MAGENTA)%15s : $(BLUE)%-20s$(GREEN) done \n" $(NAME) $(<F)
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
