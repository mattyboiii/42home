/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 08:24:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	print_c;
	int	i;

	va_start(args, format);
	print_c = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			print_c += format_handler(format[i + 1], args);
			i++;
		}
		else
			print_c += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return(print_c);
}

int	format_handler(char format, va_list args)
{
	int	print_c;

	print_c = 0;
	if (format == 'c')
		print_c += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_c += ft_putstr(va_arg(args, char *));
	/*
	else if (format == 'p')
	{
		print_c += ft_putstr("0x");
		print_c += ft_putptr(va_arg(args, uintptr_t), BASE16LOWER);
	}
	else if (format == 'd' || format == 'i')
		print_c += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_c += ft_u_putnbr_base(va_arg(args, unsigned int), BASE10);
	else if (format == 'x')
		print_c += ft_u_putnbr_base(va_arg(args, unsigned int), BASE16LOWER);
	else if (format == 'X')
		print_c += ft_u_putnbr_base(va_arg(args, unsigned int), BASE16UPPER);
	else if (format == '%')
		print_c += ft_putchar('%');
	*/
	return (print_c);
}
