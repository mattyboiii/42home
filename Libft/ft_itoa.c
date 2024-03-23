/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:34:07 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 09:51:00 by mtripodi         ###   ########.fr       */
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

static int countdig(int n)
{
	int	count;

	count = 0;
	if (n < 0)
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
	int		count;
	int		i;
	int		nn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == 0)
		return (ft_strdup("0"));
	count = countdig(n);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);

//	printf("len of count + 1: %d\n", count + 1);
	if (n < 0)
	{
		nn = 1;
		n = -n;
	}
	num[count] = '\0';

	i = count - 1;
	while (i >= 0)
	{
		num[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	if (nn == 1)
		num[0] = '-';
	return (num);
}
