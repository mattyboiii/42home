/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:04:08 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/22 20:56:48 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*This function divides parameters a by b and stores the result in the 
 * int pointed by div. It also stores the remainder of the division
 * of a by b in the int pointed by mod.*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	sum;
	int	remainder;

	remainder = a % b;
	sum = a / b;
	*div = sum;
	*mod = remainder;
}
/*
int	main(void)
{
	int n1;
	int n2;
	int *pdiv = &n1;
	int *pmod = &n2;

	n1 = 66;
	n2 = 7;
		
	printf("66 / 7 = 9, but right now pdiv = %d\n", *pdiv);
	printf("66 %% 7 = 7, but right now pdiv = %d\n", *pmod);
	ft_div_mod(n1, n2, pdiv, pmod);
	printf("now *pdiv = %d\n", *pdiv);
	printf("now *pmod = %d\n", *pmod);
	return (0);
}
*/
