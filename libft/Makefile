# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:34:21 by glovichi          #+#    #+#              #
#    Updated: 2013/12/15 18:52:36 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_backwrd.c		\
	  ft_cmpstr.c		\
	  ft_lnknbr.c		\
	  ft_putnbr.c		\
	  ft_putstr.c		\
	  ft_showhid.c		\
	  ft_strlen.c		\
	  ft_subside.c

HEAD = ./includes/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

re:	fclean all
