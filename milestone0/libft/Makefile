# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 19:13:49 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/05/03 15:05:39 by marvin           ###   ########.fr        #
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
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJ_DIR = obj
OBJECTS	= $(SRC:%.c=$(OBJ_DIR)/%.o)

# All needs to be always the first rule
all: $(OBJ_DIR) | $(NAME)

# Creating the static library
$(NAME): $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)

# Creating a directory to hide objects
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Object compilation
obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	rm -rf obj

# Full clean
fclean: clean
	rm -f $(NAME)

# Recompile all from the beggining
re: fclean all

.PHONY: all clean fclean re
