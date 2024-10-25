/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:03:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 11:06:18 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_start, va_arg, va_end, va_copy
# include <unistd.h> // write
# include <stddef.h> // size_t
// # include <stdint.h>

// Functions in my ft_printf.c
// --------- -- -- -------

int		ft_printf(const char *format, ...);
int		format_handler(char format, va_list args);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(unsigned long n, char *base);
int		ft_putnbr(int n);
int		ft_putnbr_base(unsigned int n, char *base);
size_t	ft_strlen(const char *s);
#endif
