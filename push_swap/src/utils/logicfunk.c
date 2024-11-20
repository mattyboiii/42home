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

// int	push_prep(t_node **a, t_node **b, t_node *hold, t_node *s_chunk)
// {
// 	int		size;
// 	int		chunk_bot;

// 	push_prep_fc(a, b, hold, s_chunk);
// 	chunk_bot = n_chunk_bot(*b, s_chunk->chunk);
// 	size = ft_lstlast(*a)->pos + 1;
// 	if (chunk_bot >= 2 && hold->num > (*b)->num)
// 		push_prep_rev(a, b, hold, chunk_bot);
// 	else if (s_chunk->chunk > 1 && hold->pos > size / 2)
// 	{
// 		while ((*a) != hold)
// 			rrs(a, 1);
// 		rot_large(b, hold, s_chunk->chunk);
// 	}
// }

// use push prep, if the number being pushed cant be pushed in order. Hold the top number
// using a_hold logic. Which swaps, then rotates a stack/double rotates a stack.


/* somthing to do with holding onto the clsoe numbers using swap when a number
is already at the top, if a number at the top of a is < chunk_div, then I dont need
to push the number back to the node, I can just swap and rotate to try and get the next
hold number closer up, while also finding the right position.*/

int	rotate_prep(t_node **a, t_node **b, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;

	if ((*b == NULL || ft_lstlast(*b)->pos <= 1))
		return (0);
	rb = order_rot_push(b, hold, chunk);
	rrb = order_rev_push(b, hold, chunk);
	if (rb <= rrb)
		return (rb);
	else if (rb > rrb)
		return (rrb *= -1);
}

int	closest_hold(t_node **a, t_node **b, t_node **hold_a, t_node **future)
{
	int		size;
	int		rotate;
	t_node	*hold;
	// the closest, and its future number. if hold_A is the closest, and future
	*hold_a = hold_first(*a, (*a)->div, 0);
	*future = hold_second(*a, (*a)->div, 0);
	size = ft_lstlast(*a)->pos + 1;
	if (hold_a && (!(*future) || (*hold_a)->pos < size - (*future)->pos))
	{
		rotate = 1;
		hold = *hold_a;
	}
	else if ((*future) && (!hold_a || (*hold_a)->pos > size - (*future)->pos))
	{
		hold = *future;
		rotate = -1;
	}
	if (rotate >= 0)
		*future = hold_first(*a, (*a)->div, 1);
	if (rotate < 0)
		*future = hold_second(*a, (*a)->div, 1);
	*hold_a = hold;
	return (rotate);
}

// find out if I am rot or rev to get the number in order. because I will continually
// just swap the top numbers of both stacks untill one fits. Then move onto the next.

void	ra_or_rra(t_node **a, t_node **b, int chunk)
{
	int			rotate;
	int			size;
	t_node		*hold_a;
	t_node		*hold_b;

	size = ft_lstlast(*a)->pos + 1;
	rotate = closest_hold(a, b, &hold_a, &hold_b);
	if (rotate >= 0)
		push_prep_rot(a, b, hold_b, size);
	if (rotate < 0)
		push_prep_rev(a, b, hold_b, size);
	print_lstnums(*a, *b);
}
/*
void	ra_or_rra(t_node **a, t_node **b, int chunk)
{
	t_node		*last;
	t_node		*hold_a;
	t_node		*hold_b;
	static t_node *s_chunk;

	if (!s_chunk || s_chunk->chunk != chunk)
		s_chunk = sorted_chunk(*a, s_chunk, chunk, (*a)->div);
	hold_a = hold_first(*a, (*a)->div, 0);
	hold_b = hold_second(*a, (*a)->div, 0);
	last = ft_lstlast(*a);
	if (hold_a && (!hold_b || hold_a->pos <= last->pos - hold_b->pos))
		push_prep(a, b, hold_a, s_chunk);
	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))
		push_prep(a, b, hold_b, s_chunk);
}
*/

void	sort_to_a(t_node **a, t_node **b, int chunk)
{
	int		size;
	t_node *big;

	while (*b)
	{
		size = ft_lstlast(*b)->pos + 1;
		set_big_small(b, &big, 0);
		if (big->pos < size / 2)
			rot_machine(b, big->pos, 1);
		else if (big->pos > size / 2)
			rev_machine(b, size - big->pos, 1);
		pa(a, b, 1);
	}
}


void	sort_to_b(t_node **a, t_node **b)
{
	int		chunk_div;
	int		chunk_add;
	int		chunk;

	print_lstnums(*a, *b);
	chunk = 1;
	chunk_div = get_chunk_number(*a);
	chunk_add = chunk_div;
	update_chunk_div(*a, chunk_div, chunk);
	while (chunk_size(*a, chunk))
	{
		while (check_lg_sm(*a, chunk_div + 1, 0, 0) == 1)
			ra_or_rra(a, b, chunk);
		if (*a)
			chunk++;
		chunk_div = chunk_div + chunk_add;
	}
	sort_to_a(a, b, chunk);
}
