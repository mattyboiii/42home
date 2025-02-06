/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 15:35:05 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_logic(t_stacks *stack, int iterations, int skip)
{
	int			f_rotate;
	int			m_rotate;
	t_node		*fr_hold;
	t_node		*man_hold;

	fr_hold = NULL;
	man_hold = NULL;
	skip = 0;
	f_rotate = 100;
	m_rotate = 0;
	if (stack->bsize >= 8)
		printf("");
	//print_stacks(*stack);
	if (stack->asize >= 2)
		f_rotate = force_rotate(*stack, &fr_hold, iterations, skip);
	m_rotate = manual_rotate(*stack, &man_hold, iterations, skip);
	if (posnum(f_rotate) <= m_rotate)
		return (rotate_run(stack, fr_hold, f_rotate));
	else
		return (manual_run(stack, man_hold));
}

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

int	sort_to_b(t_stacks *stack)
{
	int		chunk_div;
	int		chunk_add;
	int		chunk;
	int		total;
	int		last_melon;

	total = 0;
	chunk = 1;
	chunk_div = get_chunk_number(stack->a);
	chunk_add = chunk_div;
	update_chunk_div(stack->a, chunk_div, chunk);
	while (stack->asize > 1)
	{
		while (check_lg_sm(stack->a, chunk_div + 1, chunk, 0) == 1
			&& stack->asize > 1)
			total += compare_logic(stack, 2, 0);
		if (stack->a)
			chunk++;
		chunk_div = chunk_div + chunk_add;
		update_chunk_div(stack->a, chunk_div, chunk);
	}
	last_melon = stack->a->num;
	total += sort_to_a(stack, last_melon, 1);
	return (total);
}

void	set_holds(t_hold *hold, t_node *gold_hold, int iterations)
{
	hold->fh = NULL;
	hold->sh = NULL;
	hold->gold = gold_hold;
	hold->temp = NULL;
	hold->iterations = iterations;
	hold->ops = 100;
	hold->rotate = 0;
	hold->gold_rotate = 0;
	hold->compare = 0;
}
