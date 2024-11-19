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
// 		push_prep_rrr(a, b, hold, chunk_bot);
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

int	future_prep(t_node **a, t_node **b, t_node *hold_a, t_node *hold_b)
{
	int		hold;
	int		size;
	t_node	*hold_future;
	t_node	*afut;
	t_node	*bfut;

	size = ft_lstlast(*a)->pos + 1;
	afut = hold_first(*a, (*a)->div, 1);
	bfut = hold_second(*a, (*a)->div, 1);
	hold_future = afut->pos;

	if (hold_a && (!hold_b || hold_a->pos ))
		if ((size - hold_b->pos) < afut->pos)
			hold_future = hold_b;
	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))

	if ((size - bfut->pos) < hold_future)









}

int	push_prep(t_node **a, t_node **b, t_node *hold, t_node *s_chunk)
{
	int		size;
	int		rotate;
	int		order;
	t_node	*hold_copy;

	order = order_check(b, s_chunk->chunk);
 	size = ft_lstlast(*a)->pos + 1;
	hold_copy = copy_node(hold);
	push_prep_rc(a, b, hold, s_chunk);
	if (hold->pos < size / 2)
		push_prep_rr(a, b, hold, rotate);
	else if (hold->pos > size / 2)
		push_prep_rrr(a, b, hold, rotate);
}
// my new idea is to nor care about sorting in stack b. But make sure numbers close
// to eachother spawn from the middle. Eg 012 can all be in the middl 4 5 can be top or
// bottom.

void	push_prep_rc(t_node **a, t_node **b, t_node *hold, t_node *s_chunk)
{
	int		rb;
	int		rrb;
	int		size;
	t_node	*copy;

	if (order_check(b, s_chunk->chunk) == 1)
	{
		copy = copy_node(hold);
		size = ft_lstlast(*a)->pos + 1;
		rb = order_rot_push(b, copy, s_chunk->chunk);
		rrb = order_rev_push(b, copy, s_chunk->chunk);
		if (hold->pos < size / 2)
			push_prep_rr(a, b, hold, rb);
		else if (hold->pos > size / 2)
			push_prep_rrr(a, b, hold, rrb);
		ft_lstclear(&copy);
		print_lstnums(*a, *b);
	}
	else
	{
		while (cozy_pos(b, hold, s_chunk) < 2)
			push_prep_rr(a, b, hold, 1);
	}
}

// find out if I am rot or rev to get the number in order. because I will continually
// just swap the top numbers of both stacks untill one fits. Then move onto the next.


void	ra_or_rra(t_node **a, t_node **b, int chunk)
{
	int			rb;
	int			rrb;
	t_node		*last;
	t_node		*hold_a;
	t_node		*hold_b;

	hold_a = hold_first(*a, (*a)->div, 0);
	hold_b = hold_second(*a, (*a)->div, 0);
	last = ft_lstlast(*a);
	if (hold_a && (!hold_b || hold_a->pos <= last->pos - hold_b->pos))

	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))
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

	chunk = 1;
	chunk_div = get_chunk_number(*a);
	chunk_add = chunk_div;
	update_chunk_div(*a, chunk_div);
	while (chunk_size(*a, 0))
	{
		while (check_lg_sm(*a, chunk_div + 1, 0, 0) == 1)
			ra_or_rra(a, b, chunk);
		if (*a)
			chunk++;
		chunk_div = chunk_div + chunk_add + 1;
	}
	sort_to_a(a, b, chunk);
}
