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


// if rb_rrb = 1, it means that the hold numer needs to use ra to get to the
// correct push position. So i use rotate functions, not revers rotate funciotns.
int	order_cozy_prep(t_node **b, t_node *hold, t_node *s_chunk, int rb_rrb)
{
	int		r_order;
	int		r_cozy;

	r_order = 10000;
	if (chunk_size(*b, s_chunk->chunk) < 2)
		return (0);
	if (rb_rrb == 1 || rb_rrb == 3)
	{
		if (rb_rrb == 1)
			r_order = order_rot_push(b, hold, s_chunk->chunk);
		r_cozy = cozy_rot_push(b, hold, s_chunk, 3);
	}
	else if (rb_rrb == 2 || rb_rrb == 4)
	{
		if (rb_rrb == 2)
			r_order = order_rev_push(b, hold, s_chunk->chunk);
		r_cozy = cozy_rev_push(b, hold, s_chunk, 3);
	}
	if (r_order - 1 <= r_cozy)
		return (r_order);
	else
		return (r_cozy);
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
	if (order == 1 && hold->pos < size / 2)
		order = 1;
	else if (order == 1 && hold->pos > size / 2)
		order = 2;
	else if (order == 0 && hold->pos < size / 2)
		order = 3;
	else if (order == 0 && hold->pos > size / 2)
		order = 4;
	rotate = order_cozy_prep(b, hold_copy, s_chunk, order);
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

void	ra_or_rra(t_node **a, t_node **b, int chunk, int chunk_div)
{
	t_node		*last;
	t_node		*hold_a;
	t_node		*hold_b;
	static t_node *s_chunk;

	if (!s_chunk || s_chunk->chunk != chunk)
		s_chunk = sorted_chunk(*a, s_chunk, chunk, chunk_div);
	hold_a = hold_first(*a, chunk_div, 0);
	hold_b = hold_second(*a, chunk_div, 0);
	last = ft_lstlast(*a);
	if (hold_a && (!hold_b || hold_a->pos <= last->pos - hold_b->pos))
		push_prep(a, b, hold_a, s_chunk);
	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))
		push_prep(a, b, hold_b, s_chunk);
	(*a)->chunk = chunk;
	pb(a, b, 1);
	print_lstnums(*a, *b);
}

t_node	*sorted_chunk(t_node *a, t_node *s_chunk, int chunk, int chunk_div)
{
	if (!s_chunk || s_chunk->chunk != chunk)
		ft_lstclear(&s_chunk);
	while (a)
	{
		if (a->num <= chunk_div)
		{
			ft_lstadd_back(&s_chunk, ft_lstnew(a->num, a->pos, a->stack[0]));
			ft_lstlast(s_chunk)->chunk = chunk;
		}
		a = a->next;
	}
	s_chunk = simple_sort(s_chunk);
	return (s_chunk);
}

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
	while (chunk_size(*a, 0))
	{
		while (check_lg_sm(*a, chunk_div + 1, 0, 0) == 1)
			ra_or_rra(a, b, chunk, chunk_div);
		if (*a)
			chunk++;
		chunk_div = chunk_div + chunk_add + 1;
	}
	sort_to_a(a, b, chunk);
}
