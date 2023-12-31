/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:42:17 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/09 16:29:09 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	numc;
	int	i;

	numc = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * numc);
	if (*range == NULL)
	{
		return (-1);
	}
	else
	{
		i = 0;
		while (min < max)
			(*range)[i++] = min++;
		return (numc);
	}
}
/*
int	main(void)
{
	int	 min = 0;
	int	max = 10;
	int	*range;
	int	i = 0;
	int size = ft_ultimate_range(&range, min, max);

	printf("size of range %d\n", size);
	while (i < max)
	{
		printf("range[%d] = %d\n", i, range[i]);
		i++;
	}

	printf("\n");
	free(range);
	return (0);
}
*/
