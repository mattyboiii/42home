/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 21:23:15 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-03 21:23:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// comp = compare
int	order_check(t_node **lst, int chunk)
{
	int		cut;
	t_node	*big;
	t_node	*comp;
	t_node	*old_next;

	if (chunk_size(*lst, chunk) <= 2)
		return (1);
	set_big_small(lst, &big, 0);
	cut = make_chunk_circle(lst, &old_next, chunk);
	comp = big->next;
	while (comp != big && comp->chunk == chunk)
	{

		if (comp->num > comp->prev->num)
		{
			cut_circle(lst, old_next, cut);
			return (0);
		}
		comp = comp->next;
	}
	cut_circle(lst, old_next, cut);
	return (1);
}

// for now, i am just going to check if the number is within 2 next or prev
// rc = rotate count.

int	order_rot_push(t_node **b, t_node *node, int chunk)
{
	int		rot;
	int		push_num;

	if (chunk_size(*b, chunk) < 2)
		return (0);
	rot = 0;
	push_num = node->num;
	node->chunk = chunk;
	pb(&node, b, 0);
	while (order_check(b, chunk) == 0)
	{
		if ((*b)->num == push_num)
			pa(&node, b, 0);
		r(b, 0);
		rot++;
		node->chunk = chunk;
		pb(&node, b, 0);
	}
	pa(&node, b, 0);
	rev_machine(b, rot, 0);
	return (rot);
}

int	order_rev_push(t_node **b, t_node *node, int chunk)
{
	int		rev;
	int		push_num;

	if (chunk_size(*b, chunk) < 2)
		return (0);
	rev = 0;
	push_num = node->num;
	node->chunk = chunk;
	pb(&node, b, 0);
	while (order_check(b, chunk) == 0)
	{
		if ((*b)->num == push_num)
			pa(&node, b, 0);
		rrs(b, 0);
		rev++;
		node->chunk = chunk;
		pb(&node, b, 0);
	}
	pa(&node, b, 0);
	rot_machine(b, rev, 0);
	return (rev);
}
