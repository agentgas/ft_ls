# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:34:21 by glovichi          #+#    #+#              #
#    Updated: 2013/12/15 18:52:34 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c

SRC2= ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)

HEAD = ./libft/includes

all: $(NAME)

$(NAME):
	make -C ./libft/
	$(CC) $(SRC) $(SRC2) -I $(HEAD) -o $(NAME)

clean:
	make -C ./libft/ clean
	rm -f $(NAME)

fclean: clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re:	fclean all

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
