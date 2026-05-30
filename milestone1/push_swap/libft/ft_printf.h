/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:43:56 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 17:01:57 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

/**
* @brief write output to stdout according to a specific format
* @param str string to print
* @return count of printed characters
*/
int		ft_printf(char const *str, ...);

/**
* @brief print a character
* @param c character to print
* @param count pointer to the count of printed characters
*/
void	ft_printchar(char c, int *count);

/**
* @brief print a string
* @param str string to print
* @param count pointer to the count of printed characters
*/
void	ft_printstr(char *str, int *count);

/**
* @brief cast a number to a string
* @param n number to cast
* @param base len_base: length of the base
* @param flag base to cast the number
* @param count pointer to the count of printed characters
*/
void	ft_castnbr(long long n, int base, int flag, int *count);

/**
* @brief cast an unsigned number to a string
* @param n number to cast
* @param len_base length of the base
* @param str base to cast the number
* @param count pointer to the count of printed characters
*/
void	ft_unsigned_castnbr(unsigned long long n, int base,
			int flag, int *count);

#endif