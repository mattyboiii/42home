/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:33 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/18 11:47:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_putchar
** ------------------------
** Prototype: int ft_putcharchar c);
**
** Parameters:
**    n: integer handed into the function.
**    base: the string of chars handed into the function.
**
** Return value: integer of the amount of bytes written.
**
** External functions: none
**
** Description:
**    Outputs the unsigned integer to the fd depending on the base handed in.
**    similar to ft_putnbr but you dont have to print the prefix first.
*/

#include "ft_printf.h"

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
