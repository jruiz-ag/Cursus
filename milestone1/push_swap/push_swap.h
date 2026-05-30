/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:05:28 by lupin             #+#    #+#             */
/*   Updated: 2026/05/28 13:40:18 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <limits.h>
# define ERROR -1

/**
 * @enum e_order
 * @brief Enumeration to represent the order of elements in the stack.
 * @var ASC: Elements are ordered in ascending order.
 * @var DESC: Elements are ordered in descending order.
 */
typedef enum e_order
{
	ASC,
	DESC
}	t_order;

/**
 * @enum e_options
 * @brief Enumeration to represent the different algorithm options for sorting.
 * @var SIMPLE: Use a simple sorting algorithm.
 * @var MEDIUM: Use a medium complexity sorting algorithm.
 * @var COMPLEX: Use a complex sorting algorithm.
 * @var ADAPTATIVE: Automatically select the best algorithm 
 * based on the disorder index.
 * @var BENCH: Display information about the sorting process.
 */
typedef enum e_options
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
	BENCH
}	t_options;

typedef struct s_bench
{
	double	disorder_idx;
	char	*strategy;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

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
 * @param ctr The struct to do the benchmark.
 */
void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

/**
 * @brief Take the first element from stack a and place it at the top of stack b.
 * @note It does nothing if a is empty.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The struct to do the benchmark.
 */
void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

/**
 * @brief Take the first two elements from stack a and swap them.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 * @param ctr The struct to do the benchmark.
 */
void	sa(t_stack **stack_a, t_bench *ctr);

/**
 * @brief Take the first two elements from stack b and swap them.
 * @note It does nothing if b is empty or only has one element.
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The struct to do the benchmark.
 */
void	sb(t_stack **stack_b, t_bench *ctr);

/**
 * @brief Take the first two elements from stack a and stack b and swap them.
 * @note It swap any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The struct to do the benchmark.
 */
void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack a up, 
 * making the first element the last.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 * @param ctr The struct to do the benchmark.
 */
void	ra(t_stack **stack_a, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack b up, 
 * making the first element the last.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 * @param ctr The struct to do the benchmark.
 */
void	rb(t_stack **stack_b, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack b and stack a up, 
 * making the first element the last.
 * @note It rotate any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The struct to do the benchmark.
 */
void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack a down, 
 * making the last element the first.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 * @param ctr The struct to do the benchmark.
 */
void	rra(t_stack **stack_a, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack b down, 
 * making the last element the first.
 * @note It does nothing if a is empty or only has one element.
 * @param stack_a Pointer to any node of stack a.
 * @param ctr The struct to do the benchmark.
 */
void	rrb(t_stack **stack_b, t_bench *ctr);

/**
 * @brief Moves all of the elements in stack b and stack a down, 
 * making the last element the first.
 * @note It reversed rotate any stack if has at least two elements.
 * @param stack_a Pointer to any node of stack a. 
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The struct to do the benchmark.
 */
void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

/**
 * @brief Sorts the elements in stack a using insertion sort algorithm.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param control The struct to do the benchmark.
 * @return 0 on success, or ERROR if an error occurs.
 */
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_bench *control);

/**
 * @brief Prints the values in the list.
 * @param lst Pointer to the first node of the list.
 */
void	print_list(const t_stack *lst);

/**
 * @brief Computes the disorder index of the stack.
 * @param stack Pointer to any node of the stack.
 * @return The disorder index calculated, or ERROR on failure.
 */
double	compute_disorder(t_stack *stack);

/**
 * @brief Evaluate a stack to be ordered.
 * @param stack Pointer to any node of the stack.
 * @return 1 if it is ordered, 0 if not, or ERROR on failure.
 */
int		is_order(t_stack *stack);

/**
 * @brief Rotate the stack to bring the element 
 * at the specified position to the top
 * @param stack The stack to rotate
 * @param pos The position of the element to bring to the top.
 * @param control The benchmar to control the movements.
 * @param elec The stack selected for the move.
 */
void	rotate_stack(t_stack **stack, int pos, t_bench *control, char elec);

/**
 * @brief Find the maximum value in the stack
 * @param stack The stack to search
 * @return The maximum value in the stack
 */
int		max_value(t_stack *stack);

/**
 * @brief Find the position into stack where value is
 * @param stack The stack to search
 * @param value The value to be found
 * @return The position where value is found, or -1 if isnt found
 */
int		pos_of_value(t_stack *stack, int value);

/**
 * @brief Sorts the elements in stack a using sort by chunks.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param control The struct to do the benchmark.
 */
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *control);

/**
 * @brief Print the error message and perform a correct exit.
 * @return ERROR cause a problem has been occurred.
 */
int		error(void);

/**
 * @brief Sorts the elements in stack a using sort by radix.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param control The struct to do the benchmark.
 */
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *control);

/**
 * @brief Extracts all of the numbers in a string by a safe way.
 * @param argv The string which can contain more than one number.
 * @param lst Pointer to any node of stack.
 * @return 0 if all is correct, ERROR in other wat.
 */
int		get_argv(char *argv, t_stack **lst);

/**
 * @brief Transform the array to simplify the numbers and use minimum bits,
 * assigning them the relative pos in an ordered list.
 * @param stack Pointer to any node of stack.
 */
void	assign_index(t_stack **stack);

/**
 * @brief Initialize the structure to count the benchmark.
 * @param bench Pointer to the control struct.
 * @param disorder_idx Grade of disorder of the list.
 * @param flag Represent the algorithm chosen.
 */
void	initialize_bench(t_bench *bench, double disorder_idx, int flag);

/**
 * @brief Print the benchmark result.
 * @param bench Pointer to the control struct.
 */
void	print_bench(t_bench *bench);

/**
 * @brief Control a safe exit by freeing both stacks.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param status The exit status.
 */
void	free_both(t_stack **stack_a, t_stack **stack_b, int status);

/**
 * @brief Order the list in the best way when its small.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param ctr The bench struct where we control the movements.
 */
void	small_sort(t_stack **stack_a, t_stack **stack_b, t_bench *ctr);

#endif