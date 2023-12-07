/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:05:01 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/06 17:47:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	sqr;

	sqr = 0;
	if (nb < 0)
	{
		return (0);
	}
	while ((sqr * sqr) <= nb && sqr <= 46340)
	{
		if ((sqr * sqr) == nb)
			return (sqr);
		sqr++;
	}
	return (0);
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

   num = 4;
   num2 = 6;
   num3 = 8;
   printf("ft_rf 2 = %d\n", ft_sqrt(num));
   printf("ft_rf 3 = %d\n", ft_sqrt(16));
   printf("ft_rf 3 = %d\n", ft_sqrt(2147395600));
   return (0);
   }
   */
