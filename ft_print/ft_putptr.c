/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:24:07 by mtripodi          #+#    #+#             */
/*   Updated: 2024/05/22 11:38:00 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putptr
** ------------------------
** Prototype: int ft_putptr(unsigned long n, char *base);
**
** Parameters:
**    n: the memory address of the pointer handed in.
**    base: the string of characters deciding the base to use
**
** Return value: integer of the amount of bytes written.
**
** External functions: none
**
** Description:
**    prints out the memory address to the fd by using recursion
**    to get the correct number. Using the base_len allows for the
**    correct character to be output and also allows for the ablity
**     to use another base.
*/

#include "ft_printf.h"

int	ft_putptr(unsigned long n, char *base)
{
	size_t	print_c;
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
