/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/29 12:31:37 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
*/

int main(int arc, char **arv)
{
	s_node *a;
	// s_node *b;

	if (arc == 1)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	a = fill_a(arc, arv);
}
