/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:03:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 08:37:45 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_start, va_arg, va_end, va_copy
# include <unistd.h> // write
# include <stddef.h> // size_t

// Functions in my ft_printf.c
// --------- -- -- -------


int	ft_printf(const char *format, ...);
int	format_handler(char format, va_list args);

int	ft_putchar(char c);
int	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

# endif
