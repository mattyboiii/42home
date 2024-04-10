/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:00:26 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/23 16:09:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		sum;
	int		rem;
	int		tempa;
	int		tempb;

	tempa = *a;
	tempb = *b;
	sum = tempa / tempb;
	rem = tempa % tempb;
	*a = sum;
	*b = rem;
}

/*
int	main(void)
{
	int n1;
	int n2;

	n1 = 66;
	n2 = 7;

	printf("66 / 7 = 9, rn n1 = %d\n", n1);
	printf("66 %% 7 = 9, rn n2 = %d\n", n2);
	ft_ultimate_div_mod(&n1, &n2);
	printf("now n1 = %d\n", n1);
	printf("now n2 = %d\n", n2);
	return (0);
}
*/
