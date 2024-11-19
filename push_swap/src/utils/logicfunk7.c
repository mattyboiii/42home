/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 01:47:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-17 01:47:50 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cozy_pos(t_node **b, t_node *hold, t_node *s_chunk)
{
	int		rotate;
	int		top_bun;
	int		bot_bun;
	t_node	*big;
	t_node	*small;
	t_node	*copy;

	copy = copy_lst(b);
	set_big_small(b, &big, &small);


}

int	cozy_pos_rotate(t_node *b_copy, t_node *hold, int top_bun, int bot_bun)
{
	int		rotate;

	rotate = 0;
	while (b_copy->num > hold->num)
	{
		r(&b_copy, 0);
		rotate++;
	}
	return (rotate);
}


int	cozy_rot_push(t_node **b, t_node *hold, t_node *s_chunk, int range)
{
	int		rot;
	int		size;

	rot = 0;
	hold->chunk = s_chunk->chunk;
	size = chunk_size(*b, s_chunk->chunk);
	if (size < range)
		range = size - 1;
	while (cozy_pos(b, hold, s_chunk) <= range)
	{
		r(b, 0);
		rot++;
	}
	rev_machine(b, rot, 0);
	return (rot);
}

int	cozy_rev_push(t_node **b, t_node *hold, t_node *s_chunk, int range)
{
	int		rev;
	int		size;

	rev = 0;
	hold->chunk = s_chunk->chunk;
	size = chunk_size(*b, s_chunk->chunk);
	if (size < range)
		range = size - 1;
	while (cozy_pos(b, hold, s_chunk) != range)
	{
		rrs(b, 0);
		rev++;
	}
	rot_machine(b, rev, 0);
	return (rev);
}

void sort_buns(t_node *lst, t_node *hold, int *top_bun, int *bot_bun)
{
	int		cut;
	int		rotate;
	t_node	*old_next;

	rotate = 2;
	cut = make_chunk_circle(&lst, &old_next, lst->chunk);
	while (lst->num != hold->num)
		lst = lst->next;
	*top_bun = lst->prev->num;
	*bot_bun = lst->next->num;
	cut_circle(&lst, old_next, cut);
}
