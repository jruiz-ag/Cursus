# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/19 19:26:12 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/11/19 19:54:32 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -rf

SRCS = main.c parser.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADER = codexion.h
NAME = codexion

# All needs to be always the first rule
all: $(NAME)

# Creating the executable
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	@$(RM) $(OBJ_DIR)
	@echo "Objects removed"

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@echo "Full clean done"