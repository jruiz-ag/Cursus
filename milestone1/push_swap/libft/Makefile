# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/26 14:49:38 by lupin             #+#    #+#              #
#    Updated: 2026/05/24 01:16:00 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_in_array.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_bit_value.c \
	  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_sqrt.c ft_strmapi.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_cont_bits.c \
	  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	  ft_destroyer.c ft_del.c ft_strjoin_free_s1.c ft_strjoin_free_s2.c ft_split_destroyer.c\
	  get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME = libft.a

RM = rm -rf

HEADER = libft.h get_next_line.h ft_printf.h

# All needs to be always the first rule
all: $(NAME)

# Creating the static library
$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	@$(RM) $(OBJ_DIR)
	@echo "Libft objects cleaning done."

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@echo "Libft full cleaning done."

# Recompile all from the beggining
re: fclean all
	@echo "Libft rebuild done"

.PHONY: all clean fclean re
#.PHONY indicates that all, clean, fclean, and re are not files to be generated, but action targets