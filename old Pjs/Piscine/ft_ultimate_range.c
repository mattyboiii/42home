/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:42:17 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/07 16:29:47 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int numc;

	numc = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*(range) = malloc(sizeof(int) * numc);
	if (*(range) == NULL)
	{
		*range = NULL;
		return (-1);
	}
	else 
	{
		*(range) = &numc;
		return (numc);
	}
}

int	main(void)
{
	int	 min = 0;
	int	max = 6;
	int	*range;
	int size = ft_ultimate_range(&range, min, max);

	printf("size of range %d", size);
	printf("\n");
	return (0);
}

