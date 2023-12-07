/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:06:50 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/27 12:33:55 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
	{
		int	i;
		int temp;

		i = 0;

		while (i < (size / 2))
			{
				temp = tab[i];
				tab[i] = tab[size - i - 1]; 
				tab[size - i - 1] = temp;
				i++;
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


		int	arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
		i = 0;

		printf("\narray2 used to be \n");
		while (i < 8)
		{
			printf("%d", arr2[i]);
			i++;
		}
		ft_rev_int_tab(arr2, 8);
		printf("\narray2 is now reversed\n");
		i = 0;
		while (i < 8)
		{
			printf("%d", arr2[i]);
			i++;
		}
		
	return (0);
}
