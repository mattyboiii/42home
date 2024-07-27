/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:35:10 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/06 16:11:14 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
   int main(void)
   {
   int num = 2;
   int num2 = 3;
   int num3 = 4;

   num = 0 + 1;
   printf("!num = %d\n", num);
   num2 = 0 + 1 + 1;
   printf("!num2 = %d\n", num2);
   num3 = 0 + 1 + 1 + 2;
   printf("!num3 = %d\n", num3);

   num = 6;
   num2 = 7;
   num3 = 8;
   printf("ft_rf 2 = %d\n", ft_fibonacci(num));
   printf("ft_rf 3 = %d\n", ft_fibonacci(num2));
   printf("ft_rf 3 = %d\n", ft_fibonacci(num3));
   printf("ft_rf 3 = %d\n", ft_fibonacci(40));

   return 0;
   }
   */
