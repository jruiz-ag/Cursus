/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:05:28 by lupin             #+#    #+#             */
/*   Updated: 2026/05/27 23:48:42 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <limits.h>
# define ERROR -1

/**
 * @struct s_stack
 * @brief Structure used to store stack elements.
 * @var s_stack::value Value stored in the stack element.
 * @var s_stack::index Relative position in the ordered list (For radix_sort)
 * @var s_stack::next Pointer to the next element in the stack.
 * @var s_stack::prev Pointer to the previous element in the stack.
 */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/**
 * @brief Creates a new stack node with the given content.
 * @param content Value to store in the new node.
 * @return Pointer to the newly allocated node, or NULL on failure.
 */
t_stack	*new_node(const int content);

/**
 * @brief Adds the node `new` at the beginning of the list represented by `lst`.
 * @param lst Address of the pointer to the list head (may be updated).
 * @param new Node to insert at the front.
 */
void	add_node_front(t_stack **lst, t_stack *new);

/**
 * @brief Adds the node `new` at the end of the list represented by `lst`.
 * @param lst Address of the pointer to the list head (may be updated).
 * @param new Node to insert at the back.
 */
void	add_node_back(t_stack **lst, t_stack *new);

/**
 * @brief Returns the number of elements in the list.
 * @param lst Pointer to any node of the list (function walks the list).
 * @return Number of elements in the list.
 */
int		lst_size(const t_stack *lst);

/**
 * @brief Returns the last node in the list.
 * @param lst Pointer to any node of the list.
 * @return Pointer to the last node, or NULL if list is empty.
 */
t_stack	*last_node(const t_stack *lst);

/**
 * @brief Returns the first node in the list.
 * @param lst Pointer to any node of the list.
 * @return Pointer to the first node, or NULL if list is empty.
 */
t_stack	*first_node(const t_stack *lst);

/**
 * @brief It frees the whole memory allocated for the list.
 * @param lst Pointer to any node of the list.
 */
void	free_stack(t_stack **lst);

/**
 * @brief Make the list if all is okey and memory can be allocated.
 * @param argv which is the array of strings use like numbers.
 * @return List is all is okey, NULL in other case.
 */
t_stack	*build_list(char **argv);

/**
 * @brief Take the first element from stack b and place it at the top of stack a.
 * @note It does nothing if b is empty.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 */
void	pa(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Take the first element from stack a and place it at the top of stack b.
 * @note It does nothing if a is empty.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 */
void	pb(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Take the first two elements from stack a and swap them.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 */
void	sa(t_stack **stack_a);

/**
 * @brief Take the first two elements from stack b and swap them.
 * @note It does nothing if b is empty or only has one element.
 * @param stack_b Pointer to any node of stack b.
 */
void	sb(t_stack **stack_b);

/**
 * @brief Take the first two elements from stack a and stack b and swap them.
 * @note It swap any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 */
void	ss(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Moves all of the elements in stack a up, 
 * making the first element the last.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 */
void	ra(t_stack **stack_a);

/**
 * @brief Moves all of the elements in stack b up, 
 * making the first element the last.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 */
void	rb(t_stack **stack_b);

/**
 * @brief Moves all of the elements in stack b and stack a up, 
 * making the first element the last.
 * @note It rotate any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 */
void	rr(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Moves all of the elements in stack a down, 
 * making the last element the first.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 */
void	rra(t_stack **stack_a);

/**
 * @brief Moves all of the elements in stack b down, 
 * making the last element the first.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 */
void	rrb(t_stack **stack_b);

/**
 * @brief Moves all of the elements in stack b and stack a down, 
 * making the last element the first.
 * @note It reversed rotate any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 */
void	rrr(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Prints the values in the list.
 * @param lst Pointer to the first node of the list.
 */
void	print_list(const t_stack *lst);

/**
 * @brief Evaluate a stack to be ordered.
 * @param stack Pointer to any node of the stack.
 * @return 1 if it is ordered, 0 if not, or ERROR on failure.
 */
int		is_order(t_stack *stack);

/**
 * @brief Print the error message and perform a correct exit.
 * @return ERROR cause a problem has been occurred.
 */
int		error(void);

/**
 * @brief Extracts all of the numbers in a string by a safe way.
 * @param argv The string which can contain more than one number.
 * @param lst Pointer to any node of stack.
 * @return 0 if all is correct, ERROR in other wat.
 */
int		get_argv(char *argv, t_stack **lst);

/**
 * @brief Controll a safe exit by freeing both stacks
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param status The exit status.
 */
void	free_both(t_stack **stack_a, t_stack **stack_b, int status);

#endif