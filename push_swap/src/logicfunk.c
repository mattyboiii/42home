/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 16:59:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sort to a simply finds the biggest number in stack b, and pushes
 * it to stack_a
 */
int	sort_to_a(t_stacks *stack, int last_melon, int rr)
{
	int		total;
	t_node	*big;

	total = 0;
	while (stack->b)
	{
		set_big_small(stack->b, &big, 0);
		if (big->pos < stack->asize / 2)
		{
			total += big->pos;
			rot_machine(&stack->b, big->pos, 1);
		}
		else if (big->pos > stack->asize / 2)
		{
			total += stack->bsize - big->pos;
			rev_machine(&stack->b, stack->bsize - big->pos, 1);
		}
		if (rr && stack->b->num < last_melon)
		{
			rrs(&stack->a, 1);
			rr = 0;
		}
		total += pa(stack, 1);
	}
	return (total);
}
