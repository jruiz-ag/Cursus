# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 19:13:49 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/03/21 21:44:09 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRC	= main.c errors.c atoi.c 
OBJECTS	= $(SRC:.c=.o)

all: main

main:
	$(CC) $(CFLAGS) *.c -o $(NAME)

# NAME
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# CC
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
	rm -f $(OBJECTS)

# fclean
fclean: clean
	rm -f $(NAME)

# Bonus: regla re (recompila todo desde cero)
#re: fclean $(NAME)

#//.PHONY: clean fclean re
