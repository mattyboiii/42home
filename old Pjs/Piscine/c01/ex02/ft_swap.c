/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:25:53 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/22 18:55:56 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap1;
	int	swap2;

	swap1 = *b;
	swap2 = *a;
	*a = swap1;
	*b = swap2;
}
/*
int	main(void)
{
	int a = 66; 
	int b = 42;

	printf("int a = %d\n", a);
	printf("int b = %d\n", b); 
	ft_swap(&a, &b);
	printf("SWAPPY POPPY ---- SWAPPY POPPY\n");
	printf("int a has been swapped, now a = %d\n", a);
	printf("int b has been swapped, now b = %d\n", b);
}
*/
