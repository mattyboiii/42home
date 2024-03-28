/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:55:46 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/06 13:17:47 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	int	out;

	out = 0;
	if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	else
		return (out = nb * ft_recursive_power(nb, power - 1));
}
/*
int	main(void)
{
	int num = 2;
	int num2 = 3;
	int num3 = 4;

	num = num * num * num;
	printf("!num = %d\n", num);
	num2 = num2 * num2 * num2;
	printf("!num2 = %d\n", num2);
	num3 = num3 * num3  * num3;
	printf("!num3 = %d\n", num3);

	num = 2;
	num2 = 3;
	num3 = 4;
	printf("ft_rf 2 = %d\n", ft_recursive_power(num, 3));
	printf("ft_rf 3 = %d\n", ft_recursive_power(num2, 3));
	printf("ft_rf 3 = %d\n", ft_recursive_power(num3, 3));
	printf("ft_rf 0 ^ 1 = %d\n", ft_recursive_power(0, 1));
	printf("ft_rf 66 ^ 0 = %d\n", ft_recursive_power(66, 0));
	printf("ft_rf 1 ^ 1 = %d\n", ft_recursive_power(1, 1));
	printf("ft_rf 66 ^ 1 = %d\n", ft_recursive_power(66, 1));
	return (0);
}
*/
