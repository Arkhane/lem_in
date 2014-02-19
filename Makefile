# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 15:15:22 by mmaudet           #+#    #+#              #
#    Updated: 2014/02/11 15:15:23 by mmaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re

NAME = lem-in
SRCS = main.c \
get_config.c \
room_links.c \
calc_path.c \
resolution.c \
march_of_ants.c
#libft_func.c ft_get_next_line.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft all
	gcc -Wall -Wextra -Werror -g -Ilibft/includes -c $(SRCS) $<
	gcc -Llibft -lft -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all