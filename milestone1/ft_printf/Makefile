# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 19:13:49 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/05/12 20:22:26 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
LIBC 	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr_base.c ft_putnbr_base_unsigned.c ft_putdir.c
OBJ_DIR = obj
OBJECTS	= $(SRC:%.c=$(OBJ_DIR)/%.o)

# All needs to be always the first rule
all: $(NAME)

# Creating the static library
$(NAME): $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	rm -rf $(OBJ_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Recompile all from the beggining
re: fclean all

.PHONY: all clean fclean re