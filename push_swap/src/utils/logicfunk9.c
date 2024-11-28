/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 03:50:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-25 03:50:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rot_checks_swap(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num <= stk->a->div && stk->a->next->num <= stk->a->div
			&& if_push(*stk, stk->a->next) == 1)
		s(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 0)
		rr(stk, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else if (stk->a->num <= stk->a->div && stk->a->next->num <= stk->a->div)
		r(&stk->a, out);
	else if (stk->a->num <= stk->a->div)
		s(&stk->a, out);
	return (1);
}

int	rev_checks_swap(t_stacks *stk, t_node *hold, int out)
{
	t_node		*last;

	last = ft_lstlast(stk->a);
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (last->num <= stk->a->div && if_push(*stk, last) == 1)
		rrs(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, stk->a) == 0)
		rrr(stk, out);
	else if (stk->a->num <= stk->a->div)
		s(&stk->a, out);
	return (1);
}

int	rotate_run(t_stacks *stack, t_node *hold)
{
	int		old_size;
	int		rotate;

	rotate = 0;
	old_size = stack->asize;
	if (hold->pos < stack->asize / 2)
	{
		while (old_size == stack->asize)
		{
			rotate += rot_checks_rotate(stack, hold, 1);
		}
	}
	else
	{
		while (old_size == stack->asize)
		{
			rotate += rev_checks_rotate(stack, hold, 1);
		}
	}
	return (rotate);
}

int	push_prep_swap(t_stacks stack, t_node *hold)
{
	int			old_size;
	int			rotate;
	t_stacks	stk;

	stk = stacklst_dup(stack);
	rotate = 0;
	old_size = stk.asize;
	if (hold->pos < stk.asize / 2)
	{
		while (old_size == stk.asize)
		{
			if (hold->num == 13)
				ft_printf("here\n");
			rotate += rot_checks_swap(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	else
	{
		while (old_size == stk.asize)
		{
			rotate += rev_checks_swap(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	stacklst_del(&stk);
	return (rotate);
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
