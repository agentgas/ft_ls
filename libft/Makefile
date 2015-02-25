# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:34:21 by glovichi          #+#    #+#              #
#    Updated: 2015/02/21 16:30:40 by glovichi         ###   ########.fr        #
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
	ft_strcmp.c		\
	  ft_subside.c		\
	  ft_strjoin.c		\
	  ft_putendl.c		\
	  ft_strdup.c		\
	  ft_list_train.c	\
	  ft_little_r.c		\
	  ft_ord_list.c		\
	  ft_rev_ord_list.c	\
	  ft_time_sort.c	\
		ft_longlong.c	\
		ft_itoa.c		\
		ft_list_long.c

HEAD = -I./includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)	
	@echo Libft okay Sir

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

re:	fclean all
