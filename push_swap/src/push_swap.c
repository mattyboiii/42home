/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/27 14:14:31 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_a(int arc, char **arv)
{	
	int		a*;
	int		i;
	
	a = malloc(sizeof(int) * (arc - 1));
	i = 1;
	while (arv[i])
	{
		a[i - 1] = ft_atoi(arv[i]);
		i++;
	}
	return (a);
}

int	main(int arc, char **arv)
{
	node	*a;
	node	*b;

	if (arc < 3)
		ft_exit(3);
	a = fill_a(arc, arv);
	
}
