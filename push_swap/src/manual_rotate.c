/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:06:46 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:34:14 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	least_ops_man(t_stacks stack, t_node *hold_a, t_node *hold_b,
						t_node	**gold_hold)
{
	int		ops_top;
	int		ops_bot;

	ops_top = 1000;
	ops_bot = 1000;
	if (hold_a)
		ops_top = posnum(rotate_prep(stack, hold_a, stack.a->chunk))
			+ hold_a->pos;
	if (hold_b)
		ops_bot = posnum(rotate_prep(stack, hold_b, stack.a->chunk))
			+ (stack.asize - hold_b->pos);
	if (ops_top <= ops_bot)
	{
		*gold_hold = hold_a;
		return (ops_top);
	}
	else if (ops_top > ops_bot)
	{
		*gold_hold = hold_b;
		return (ops_bot);
	}
	return (ops_top);
}

int	manual_loop(t_stacks stack, t_hold hold, t_node **gold_hold, int loop)
{
	while (loop < hold.iterations)
	{
		closest_hold(stack, &hold.fh, &hold.sh, loop);
		if (!hold.fh && !hold.sh)
			break ;
		if (!hold.gold)
			hold.ops = least_ops_man(stack, hold.fh, hold.sh, &hold.gold);
		else
			hold.compare = least_ops_man(stack, hold.fh, hold.sh, &hold.temp);
		if (hold.temp && hold.compare < hold.ops)
		{
			hold.gold = hold.temp;
			hold.ops = hold.compare;
		}
		if (hold.gold && stack.bsize < 2)
			break ;
		loop++;
	}
	*gold_hold = hold.gold;
	return (hold.ops + 1);
}

int	manual_rotate(t_stacks stack, t_node **man_hold, int loop, int skip)
{
	int			rotate;
	t_hold		hold;

	rotate = 0;
	set_holds(&hold, NULL, loop);
	rotate = manual_loop(stack, hold, man_hold, skip);
	return (rotate);
}

int	manual_run(t_stacks *stack, t_node *hold)
{
	int		rotate;
	int		operations;

	rotate = 0;
	operations = 0;
	rotate = rotate_prep(*stack, hold, stack->a->chunk);
	if (hold->pos < stack->asize / 2)
		operations = hold->pos + rotate;
	else if (hold->pos > stack->asize / 2)
		operations = (stack->asize - hold->pos) + rotate;
	if (hold->pos <= stack->asize / 2 || stack->asize <= 2)
		rot_machine(&stack->a, hold->pos, 1);
	else if (hold->pos >= stack->asize / 2)
		rev_machine(&stack->a, stack->asize - hold->pos, 1);
	if (rotate >= 0)
		rot_machine(&stack->b, rotate, 1);
	else
		rev_machine(&stack->b, posnum(rotate), 1);
	pb(stack, 1);
	return (operations + 1);
}
