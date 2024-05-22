/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:27:34 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 12:05:01 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_putnbr
 ** ----------------------------
 ** Prototype: void ft_putnbr(int n);
 **
 ** Parameters:
 **    n: The integer to output.
 **
 ** Return value: integer of the amount of bytes written.
 **
 ** External functions: write
 **
 ** Description:
 **    Outputs the integer 'n' to the given file descriptor.
 */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	print_c;
	unsigned long num;


	
	print_c = 0;
	if (n < -10)
	{
		print_c += ft_putchar('-');
		print_c += ft_putnbr(((n / 10) * -1));
		print_c += ft_putchar(((n % 10) * -1 + '0'));
	}
	if (n < 0)
	{
		print_c += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		print_c += ft_putnbr(n / 10);
	print_c += ft_putchar((n % 10) + '0');
	return (print_c);
}
