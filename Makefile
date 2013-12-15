# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 02:31:26 by cfeijoo           #+#    #+#              #
#    Updated: 2013/12/15 20:21:57 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

INCFOLDER = ./includes

SRC	=	main.c		 \
		ft_functions.c \
		hash.c			\
		get_next_line.c
	
OSRC = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -O4 -pedantic
CC = gcc

$(NAME):
	@echo "\n**** COMPILING $(NAME)\n"
	$(CC) $(CFLAGS) -I $(INCFOLDER) -c $(SRC)
	$(CC) $(CFLAGS) $(OSRC) -o $(NAME)

clean:
	if [ -f $(OSRC) ]; \
		then /bin/rm -f $(OSRC); \
	fi

fclean: clean
	if [ -f $(NAME) ]; \
		then /bin/rm -f $(NAME); \
	fi

re: fclean $(NAME)
