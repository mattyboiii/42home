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
	int		rb;
	int		rrb;
	int		size;
	t_node	*copy;

	copy = copy_node(hold);
	size = ft_lstlast(*a)->pos + 1;
	rb = pb_rot_push(copy, b, chunk);
	rrb = pb_rev_push(copy, b, chunk);
	if (hold->pos < size / 2)
		push_prep_rr(a, b, hold, rb);
	else if (hold->pos > size / 2)
		push_prep_rrr(a, b, hold, rrb);
	ft_lstclear(&copy);

}

void	push_prep_rr(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	while (prep_b > 0)
	{
		if (*a != hold)
			rr(a, b);
		else
			r(b, 1);
		prep_b--;
	}
	while (*a != hold)
		r(a, 1);

}

void	push_prep_rrr(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	while (prep_b > 0)
	{
		if (*a != hold)
			rrr(a, b);
		else
			rrs(b, 1);
		prep_b--;
	}
	while (*a != hold)
		rrs(a, 1);

}

int	check_pb_pos(t_node **a, t_node **b, int chunk)
{
	int		rb;
	int		rrb;

	if (chunk_size(*b, chunk) < 2)
		return (0);
	rb = pb_rot_push(*a, b, chunk);
	if (rb > 0 && chunk <= 1)
		rrb = pb_rev_push(*a, b, chunk);
	if (rb <= rrb)
		return (rb);
	else
		return (rrb *= -1);
}

// going to remove compare_holds howdy
void	ra_or_rra(t_node **a, t_node **b, int chunk, int chunk_div)
{
	t_node	*last;
	t_node	*hold_a;
	t_node	*hold_b;

	hold_a = hold_first(*a, chunk_div);
	hold_b = hold_second(*a, chunk_div);
	last = ft_lstlast(*a);
	print_lstnums(*a, *b);
	if (hold_a->pos <= last->pos - hold_b->pos)
		push_prep(a, b, hold_a, chunk);
	else if (hold_a->pos > last->pos - hold_b->pos)
		push_prep(a, b, hold_b, chunk);
	(*a)->chunk = chunk;
	pb(a, b, 1);
	print_lstnums(*a, *b);
}

void	sort_to_b(t_node **a, t_node **b)
{
	int		chunk_div;
	int		chunk_add;
	int		chunk;

	chunk = 1;
	chunk_div = get_chunk_number(*a);
	chunk_add = chunk_div;
	while (chunk_size(*a, 0) > 5)
	{
		while (check_lg_sm(*a, chunk_div + 1, 0, 0) == 1)
			ra_or_rra(a, b, chunk, chunk_div);
		chunk++;
		chunk_div = chunk_div + chunk_add + 1;
	}
}
