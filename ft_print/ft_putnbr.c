/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:27:34 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/25 11:22:13 by mtripodi         ###   ########.fr       */
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

int ft_putnbr(int n)
{
	size_t print_c = 0;
	unsigned int number;

	if (n < 0) {
		print_c += ft_putchar('-');
		number = -n;
	} else {
		number = n;
	}

	if (number >= 10) {
		print_c += ft_putnbr(number / 10);
	}
	print_c += ft_putchar((number % 10) + '0');

	return print_c;
}
