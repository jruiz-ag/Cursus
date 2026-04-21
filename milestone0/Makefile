# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 19:13:49 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/04/21 16:22:27 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC = cc
LIBC = ar rcs
CFLAGS	= -Wall -Wextra -Werror
SRC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c
OBJECTS	= $(SRC:.c=.o)
DEPS = libft.h

# La regla all siempre debe ser la primera
all: $(NAME)

# Creación de la librería estática
$(NAME): $(OBJECTS)
	$(LIBC) $(OBJ) -o $(NAME)

# Compilación de objetos
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de objetos
clean:
	rm -f $(OBJECTS)

# Limpieza completa
fclean: clean
	rm -f $(NAME)

# Recompila todo desde cero
re: fclean $(NAME)

.PHONY: clean fclean re

coso:
	rm a.out libft.h.gch