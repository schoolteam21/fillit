# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhelly <dhelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 15:46:42 by dhelly            #+#    #+#              #
#    Updated: 2019/02/15 17:17:52 by dhelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./libft/includes
SRC = main.c minmax.c readmap.c validcheck.c

OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./libft -lft

clean:
	rm -f libft/*.o
	rm -f $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all
