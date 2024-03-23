/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:34:07 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 10:45:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_itoa
 ** ------------------------
 ** Prototype: char *ft_itoa(int n);
 **
 ** Parameters:
 **    n: the integer to convert.
 **
 ** Return value:
 **    The string representing the integer.
 **    NULL if the allocation fails.
 **
 ** External functions: malloc
 **
 ** Description:
 **    Allocates (with malloc(3)) and returns a string representing the integer
 **    received as an argument. Negative numbers must be handled.
 */

// 2147483647, -2147483648

#include "libft.h"

static long	digcount(long n)
{
	long	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	long	nb;
	long	digc;

	nb = n;
	digc = digcount(nb);
	num = malloc(sizeof(char) * (digc + 1));
	if (num == NULL)
		return (NULL);
	num[digc--] = '\0';
	if (nb == 0)
		num[0] = '0';
	else if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		num[digc] = '0' + (nb % 10);
		nb /= 10;
		digc--;
	}
	return (num);
}
