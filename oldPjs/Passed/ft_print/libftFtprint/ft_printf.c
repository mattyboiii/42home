/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/18 11:33:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int	bytes;

	bytes = write(1, &c, 1);
	if (bytes == -1)
		return (-1);
	return (bytes);
}

int	ft_putnbr(int n)
{
	size_t			print_c;
	unsigned int	number;

	print_c = 0;
	if (n < 0)
	{
		print_c += ft_putchar('-');
		number = -n;
	}
	else
	{
		number = n;
	}
	if (number >= 10)
	{
		print_c += ft_putnbr(number / 10);
	}
	print_c += ft_putchar((number % 10) + '0');
	return (print_c);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	size_t				print_c;
	unsigned long long	base_len;
	unsigned long long	num;

	print_c = 0;
	num = n;
	base_len = ft_strlen(base);
	if (num >= (base_len))
	{
		print_c += ft_putnbr_base(num / base_len, base);
		print_c += ft_putnbr_base(num % base_len, base);
	}
	else
		print_c += ft_putchar(base[num % base_len]);
	return (print_c);
}

int	ft_putptr(unsigned long n, char *base)
{
	size_t			print_c;
	unsigned long	base_len;

	print_c = 0;
	base_len = ft_strlen(base);
	if (n >= (base_len))
	{
		print_c += ft_putptr(n / base_len, base);
		print_c += ft_putptr(n % base_len, base);
	}
	else
		print_c += ft_putchar(base[n % base_len]);
	return (print_c);
}

int	ft_putstr(char *s)
{
	int	bytes;

	bytes = 0;
	if (s)
		bytes = write(1, s, ft_strlen(s));
	else
		bytes = write(1, "(null)", 6);
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_c;
	int		i;

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
	return (print_c);
}

int	format_handler(char format, va_list args)
{
	int	print_c;

	print_c = 0;
	if (format == 'c')
		print_c += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_c += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		print_c += ft_putstr("0x");
		print_c += ft_putptr(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (format == 'd' || format == 'i')
		print_c += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_c += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		print_c += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (format == 'X')
		print_c += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (format == '%')
		print_c += ft_putchar('%');
	return (print_c);
}
