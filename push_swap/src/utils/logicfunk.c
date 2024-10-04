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
	t_node		*head;

	head = a;
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
			check_logic("sa");
			check_logic("ra");
		}

	}
}
