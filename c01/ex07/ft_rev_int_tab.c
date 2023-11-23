/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:06:50 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/23 20:07:58 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
void 	evenint(int *tab, int size)
{
	int	temp;
	int i;

	i = 0;
	while (i != size/2)
		{
			temp = tab[i];
			tab[i] = tab[size - i - 1]; 
			printf("%d\n", tab[i]);
			tab[size - i - 1] = temp;
			i++;
		}
}

void	oddint(int *tab, int size)
{
	int temp;
	int i;

	i = 0;
	while (i != size/2 + 1)
		{
			temp = tab[i];
			tab[i] = tab[size - i - 1]; 
			printf("%d\n", tab[i]);
			tab[size - i - 1] = temp;
			i++;
		}
}


void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;

	if (size % 2 == 0)
	{
		evenint(tab, size)
	}
	else (size % 2 < 0)
	{
		oddint(tab, size);
	}
}
int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 0;

	printf("array used to be \n");
	while (i < 9)
	{
		printf("%d", arr[i]);
		i++;
	}
	ft_rev_int_tab(arr, 9);
	printf("\narray is now reversed\n");
	i = 0;
	while (i < 9)
	{
		printf("%d", arr[i]);
		i++;
	}

	return (0);
}
