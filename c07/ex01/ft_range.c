/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:11:21 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/07 12:35:51 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*out;
	int	numc;
	int	i;

	out = NULL;
	if (min >= max)
		return (out);
	numc = max - min;
	out = malloc(sizeof(int) * numc);
	i = 0;
	while (min < max)
		out[i++] = min++;
	return (out);
}
/*
int	main(void)
{
	int	 min = -10;
	int	max = 7;
	int *dupog = ft_range(min, max);

	if (dupog != NULL)
	{
		int i = 0;
		while (i < max - min)
		{
			printf("%d ", dupog[i++]);
		}
		printf("\n");
		free(dupog);
	}
	return (0);
}
*/
