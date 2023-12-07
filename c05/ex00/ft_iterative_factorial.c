/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:59:53 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/07 10:05:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	sum;

	sum = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		while (nb > 0)
		{
			sum *= nb;
			nb--;
		}
		return (sum);
	}
}
/*
int	main(void)
{
	ft_iterative_factorial(1);
	write(1, "\n", 1);
	ft_iterative_factorial(2);
	write(1, "\n", 1);
	ft_iterative_factorial(3);
	write(1, "\n", 1);
	ft_iterative_factorial(4);
	write(1, "\n", 1);
	ft_iterative_factorial(6);
	return (0);
}
*/
