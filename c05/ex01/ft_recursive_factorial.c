/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:17:52 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/06 11:23:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		return (nb *= ft_recursive_factorial(nb - 1));
	}
}
/*
int	main(void)
{
	int num = 2;
	int num2 = 3;
	int num3 = 4;

	num = num * 1;
	printf("!num = %d\n", num);
	num2 = num2 * 2 * 1;
	printf("!num2 = %d\n", num2);
	num3 = num3 * 3 * 2 * 1;
	printf("!num3 = %d\n", num3);

	num = 2;
	num2 = 3;
	num3 = 4;
	printf("ft_rf 2 = %d\n", ft_recursive_factorial(num));
	printf("ft_rf 3 = %d\n", ft_recursive_factorial(num2));
	printf("ft_rf 3 = %d\n", ft_recursive_factorial(num3));

	return (0);
}
*/
