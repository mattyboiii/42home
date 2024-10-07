/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-04 07:33:29 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_node *a)
{
	t_node		*small;
	t_node		*big;

	small = a;
	big = a;
	while (a->next)
	{
		a = a->next;
		if (a->num < small->num)
			small = a;
		else if (a->num > big->num)
			big = a;
	}
	if (big->pos < 2)
	{
		if (small->pos == 0)
		{
			s(a, 1);
			r(a, 1);
		}
	}
}
