# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpin <lpin@student.42malaga.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 20:40:00 by lupin             #+#    #+#              #
#    Updated: 2026/05/30 10:44:30 by lpin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c lists/build_list.c lists/build_list_utils.c lists/linked_list_utils.c \
		lists/linked_list.c lists/error_list.c lists/bench_utils.c \
		moves/push.c moves/rotate.c moves/rev_rotate.c moves/swap.c \
		algorithms/insertion_sort.c	algorithms/chunk_sort.c algorithms/disorder_index.c algorithms/radix_sort.c algorithms/small_sort.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADER = push_swap.h
NAME = push_swap
NAME_BONUS = checker

BONUS_SRCS = bonus/checker_bonus.c bonus/lists/build_list_bonus.c bonus/lists/build_list_utils_bonus.c bonus/lists/error_list_bonus.c \
			bonus/lists/linked_list_bonus.c bonus/lists/linked_list_utils_bonus.c \
			bonus/moves/push_bonus.c bonus/moves/rev_rotate_bonus.c bonus/moves/rotate_bonus.c bonus/moves/swap_bonus.c
BONUS_OBJ_DIR = bonus/obj
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJ_DIR)/%.o)
BONUS_HEADER = bonus/push_swap_bonus.h

RM = rm -rf
LIBFT = libft/libft.a

# All needs to be always the first rule
all: $(LIBFT) $(NAME)

# Compiling at the beggining the libft
$(LIBFT):
	@$(MAKE) -C libft

# Creating the executable
$(NAME): $(OBJS) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the executable with the args given
run: all
	@./$(NAME) $(ARGS)

# Run the executable with the args given and using valgrind
valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

# Cleaning objects
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BONUS_OBJ_DIR)
	@$(MAKE) -C libft clean
	@echo "Objects removed"

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(NAME_BONUS)
	@echo "Full clean done"

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)

# Object compilation in a hide directory
$(BONUS_OBJ_DIR)/%.o: %.c $(BONUS_HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all run valgrind clean fclean re bonus
