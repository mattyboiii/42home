/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:11 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 15:17:02 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_a(t_stack_base *l, t_stack_node *t, int ca)
{
	while (ca)
	{
		if (t->above_median)
			rotate_a(l);
		else
			reverse_rotate_a(l);
		ca--;
	}
}

void	while_b(t_stack_base *l, t_stack_node *c, int cb)
{
	while (cb)
	{
		if (c->above_median)
			rotate_b(l);
		else
			reverse_rotate_b(l);
		cb--;
	}
}

static void	rotate_both_combined(t_stack_base *l, t_stack_node *c,
					t_stack_node *t, int cost[2])
{
	while (cost[0] && cost[1] && ((c->above_median && t->above_median)
			|| (!c->above_median && !t->above_median)))
	{
		if (c->above_median)
			rr(l);
		else
			rrr(l);
		cost[0]--;
		cost[1]--;
	}
}

void	rotate_both(t_stack_base *l, t_stack_node *c, t_stack_node *t)
{
	int	cost[2];
	int	sba;
	int	saa;

	sba = stack_size(l->head_b);
	saa = stack_size(l->head_a);
	if (c->above_median)
		cost[0] = c->current_position;
	else
		cost[0] = sba - c->current_position;
	if (t->above_median)
		cost[1] = t->current_position;
	else
		cost[1] = saa - t->current_position;
	rotate_both_combined(l, c, t, cost);
	while_b(l, c, cost[0]);
	while_a(l, t, cost[1]);
}

void	push_cheapest(t_stack_base *l)
{
	t_stack_node	*c;
	t_stack_node	*t;

	set_cheapest(l->head_b);
	c = l->head_b;
	while (c && !c->cheapest)
		c = c->next;
	t = c->target_node;
	if (!c->current_position && !t->current_position)
	{
		push_a(l);
		return ;
	}
	rotate_both(l, c, t);
	push_a(l);
}
