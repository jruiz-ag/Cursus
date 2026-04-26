# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 19:13:49 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/04/26 21:21:18 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
LIBC	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c
OBJECTS	= $(SRC:.c=.o)
DEPS	= libft.h

# All needs to be always the first rule
all: $(NAME)

# Creating the static library
$(NAME): $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)

# Object compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	rm -f $(OBJECTS)

# Full clean
fclean: clean
	rm -f $(NAME)

# Recompile all from the beggining
re: fclean $(NAME)

.PHONY: all clean fclean re
