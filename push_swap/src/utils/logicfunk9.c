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
	else if (stk->a->next->num <= stk->a->div && stk->a->num <= stk->a->div
			&& if_push(*stk, stk->a->next) == 1)
		s(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 0)
		rr(stk);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else
		r(&stk->b, out);
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
	else if (stk->a->next->num <= stk->a->div && if_push(*stk, stk->a->next) == 1)
		s(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 0)
		rrr(stk);
	else if (last->num <= stk->a->div && if_push(*stk, stk->a) == 0)
		rrs(&stk->b, out);
	else if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 0)
		s(&stk->a, out);
	else
		rrs(&stk->a, out);
	return (1);
}
/* I have been watching it wrong. For the first chunk, current formula is fine. Eventually
the chunks will become so big, that it will be greatly more efficient to use a
certain direction to sort the chunk b into the correct order. As going through
the entire previous 5 stacks, just because the current hold is closest to the top
isnt more efficient.

1. check closest hold, check how many rotations in both directions it would
take to sort b so when the hold is pushed it in order within b.
2. if the data is showing that it heavily favours one direction which causes a large
amount of operations then move onto the next closest hold. Check the next hold.
3. compare the stack b order data again, if it greatly favours another direction,
get the next closest hold in whichever direction. Again check what I will need
to do to order b.
4. eventually, it might just need to bite the bullet and cycle through many iterations.
5. how about do this with as many holds that are within 15 range from top/bottom.

essentially, get closest hold. Compare if ordering b is within reason. if its not
*/
int	push_prep_rotate(t_stacks *stack, t_node *hold)
{
	int		old_size;
	int		rotate;

	rotate = 0;
	old_size = stack->asize;
	if (hold->pos < stack->asize / 2)
	{
		while (old_size == stack->asize)
		{
			rotate += rot_checks(stack, hold, 1);
			print_lstnums(stack->a, stack->b);
		}
	}
	else
	{
		while (old_size == stack->asize)
		{
			rotate += rev_checks(stack, hold, 1);
			print_lstnums(stack->a, stack->b);
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
			rotate += rot_checks(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	else
	{
		while (old_size == stk.asize)
		{
			rotate += rev_checks(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	stacklst_del(&stk);
	return (rotate);
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
