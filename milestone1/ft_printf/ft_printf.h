/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:14:13 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 20:21:02 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_strlen(char const *str);
int	ft_putstr(char const *str);
int	ft_putchar(int const c);
int	ft_putnbr(int const nbr, char const *base);
int	ft_putnbr_u(unsigned int const nbr, char const *base);
int	ft_putdir(unsigned long const dir);

#endif