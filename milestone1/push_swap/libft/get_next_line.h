/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:28:07 by lupin             #+#    #+#             */
/*   Updated: 2026/05/12 20:20:15 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

/**
 * @struct s_info
 * @brief Structure used to store get_next_line state.
 *
 * @var s_info::content Buffer that stores data read until the next line.
 * @var s_info::content_size Size of @p content in bytes.
 * @var s_info::ret Line that will be returned on the next call.
 * @var s_info::fd File descriptor associated with the read state.
 */
typedef struct s_info
{
	char	*content;
	int		content_size;
	char	*ret;
	int		fd;
}				t_info;

/**
 * @brief Initialize the get_next_line state.
 *
 * @param fd File descriptor to read from.
 * @param info Pointer to the state structure to initialize.
 * @param buffer Pointer to the read buffer.
 * @return 1 on success, 0 on failure.
 */
int		init_gnl(int fd, t_info *info, char **buffer);

/**
 * @brief Check if the content contains a newline character.
 *
 * @param content String to inspect.
 * @return 1 if a newline is found, 0 otherwise.
 */
int		has_new_line(char *content);

/**
 * @brief Join two strings using a given length for the second.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param size Number of bytes from @p s2 to join.
 * @return New joined string, or NULL on failure.
 */
char	*join_content(char *s1, char *s2, int size);

/**
 * @brief Free memory and set the pointer to NULL.
 *
 * @param memory Address of the pointer to free.
 * @return NULL always, to simplify safe assignments.
 */
void	*destroy_memory(char **memory);

/**
 * @brief Extract a full line from the stored content.
 *
 * @param info get_next_line state structure.
 * @return 0 if a line was extracted or EOF, -1 error.
 */
int		extract_line(t_info *info);

/**
 * @brief Save data from the buffer into the internal state.
 *
 * @param info get_next_line state structure.
 * @param buffer Read buffer.
 * @param size Number of bytes read into the buffer.
 * @return 0 on success, -1 on failure.
 */
int		save(t_info *info, char *buffer, int size);

/**
 * @brief Read data from the descriptor and update the state.
 *
 * @param fd File descriptor.
 * @param info get_next_line state structure.
 * @param buffer Read buffer.
 * @return 0 on success or EOF, -1 on error.
 */
int		read_next_line(int fd, t_info *info, char *buffer);

/**
 * @brief Return the next line read from a file descriptor.
 *
 * @param fd File descriptor to read from.
 * @return Line including '\n' if present, or NULL on EOF or error.
 */
char	*get_next_line(int fd);

#endif
