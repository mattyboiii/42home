/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:42:17 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/07 13:54:01 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{

	int	i;
	int	*out;
	int numc;
	
	numc = max - min;
	if (min > max)
		return (NULL);
	

}

int	main(void)
{
	int	 min = -10;
	int	max = 7;
	int	**range;
	int *dupog = ft_range(range, min, max);

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

