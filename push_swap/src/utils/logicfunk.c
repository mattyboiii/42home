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

int	push_prep(t_node **a, t_node **b, t_node *hold, int chunk)
{
	int		size;
	int		chunk_bot;

	push_prep_fc(a, b, hold, chunk);
	chunk_bot = n_chunk_bot(*b, chunk);
	size = ft_lstlast(*a)->pos + 1;
	if (chunk_bot >= 2 && hold->num > (*b)->num)
		push_prep_rrr(a, b, hold, chunk_bot);
	else if (chunk > 1 && hold->pos > size / 2)
	{
		while ((*a) != hold)
			rrs(a, 1);
		rot_large(b, hold, chunk);
	}
}
// my new idea is to nor care about sorting in stack b. But make sure numbers close
// to eachother spawn from the middle. Eg 012 can all be in the middl 4 5 can be top or
// bottom. 

void	push_prep_fc(t_node **a, t_node **b, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;
	int		size;
	t_node	*copy;

	if (chunk <= 1)
	{
		copy = copy_node(hold);
		size = ft_lstlast(*a)->pos + 1;
		rb = pb_rot_push(copy, b, chunk);
		rrb = pb_rev_push(copy, b, chunk);
		if (hold->pos < size / 2)
			push_prep_rr(a, b, hold, rb);
		else if (chunk == 1 && hold->pos > size / 2)
			push_prep_rrr(a, b, hold, rrb);
		ft_lstclear(&copy);
	}
}

void	ra_or_rra(t_node **a, t_node **b, int chunk, int chunk_div)
{
	t_node	*last;
	t_node	*hold_a;
	t_node	*hold_b;

	hold_a = hold_first(*a, chunk_div, 0);
	hold_b = hold_second(*a, chunk_div, 0);
	last = ft_lstlast(*a);
	if (hold_a && (!hold_b || hold_a->pos <= last->pos - hold_b->pos))
		push_prep(a, b, hold_a, chunk);
	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))
		push_prep(a, b, hold_b, chunk);
	(*a)->chunk = chunk;
	pb(a, b, 1);
	print_lstnums(*a, *b);
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
