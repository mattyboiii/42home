/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:40 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/25 11:09:14 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h>
#include "libft/libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void pr_putnbr(int nb)
{
	unsigned long num;

	if (nb < 0)
	{
		ft_putchar('-');
		num = -nb;
	}
	else
		num = nb;
	if (num >= 10)
		pr_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

int main() {
	// Seed the random number generator (optional for better randomness)
	srand(time(NULL));

	for (int i = 0; i < 4; ++i) {
		int num;
		if (i % 2 == 0) {
			// Generate random positive number (0-9999)
			num = rand() % 10000;
		} else {
			// Generate random negative number (-9999 to 0)
			num = -(rand() % 10000);
		}

		printf("ft_putnbr = %d", num);
		printf("\n");

		printf("pr_putnbr = ");
		fflush(stdout);
		pr_putnbr(num);
		printf("\n\n");
	}

	return 0;
}

