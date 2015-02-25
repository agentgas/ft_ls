# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:34:21 by glovichi          #+#    #+#              #
#    Updated: 2015/02/24 14:28:37 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls

SRC =	ft_ls.c
	  
SRC2 =	./libft/libft.a

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

HEAD = ./libft/includes

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@$(CC) $(SRC) $(SRC2) $(CFLAGS) -I $(HEAD) -o $(NAME)
	@echo - This job is done: compilated Sir. -

clean:
	@make -C ./libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)

re:	fclean all

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
