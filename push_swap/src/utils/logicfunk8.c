/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 04:11:36 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-20 04:11:36 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rot_checks(t_node **a, t_node **b, int div)
{
	if ((*a)->num <= div && if_push(a, b, *a) == 1)
	{
		pb(a, b, 1);
		return (1);
	}
	else if ((*a)->next->num <= div && if_push(a, b, (*a)->next) == 1)
		s(a, 1);
	else if ((*a)->num > div)
		rr(a, b);
	else if ((*a)->next->num <= div && if_push (a, b, *a) == 0)
		r(b, 1);
	else if ((*a)->num <= div && if_push(a, b, *a) == 0)
	{
		s(a, 1);
		rr(a, b);
	}
	else
		r(a, 1);
	return (0);
}

int	rev_checks(t_node **a, t_node **b, t_node *last, int div)
{
	if ((*a)->num <= div && if_push(a, b, *a) == 1)
	{
		pb(a, b, 1);
		return (1);
	}
	else if (last->num <= div && if_push(a, b, last) == 1)
		rrs(a, 1);
	else if ((*a)->num > div)
		rrr(a, b);
	else if (last->num <= div && if_push (a, b, *a) == 0)
		rrs(b, 1);
	else if ((*a)->num <= div && if_push(a, b, *a) == 0)
		s(a, 1);
	else
		rrs(a, 1);
	return (0);
}

int	push_prep(t_node **a, t_node **b, int rotate, int stack_size)
{
	int		new_size;
	t_node	*last;

	new_size = stack_size;
	if (rotate > 0)
	{
		while (new_size == stack_size)
			new_size -= rot_checks(a, b, (*a)->div);
	}
	else
	{
		while (new_size == stack_size)
		{
			last = ft_lstlast(*a);
			new_size -= rev_checks(a, b, last, (*a)->div);
		}
	}
	return (new_size);
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
