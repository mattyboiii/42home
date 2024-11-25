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

/*
Home of the rotate function. The logic here will simply, look for the hold number
and ensure that the b stack is ready to accept the number. It will check if the
number under can be swapped in only. It will not swap numbers in A to preserve
their positions close to the top or bottom of stack A
*/

int	rot_checks_rotate(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 0)
		rr(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else if (stk->a->num == hold->num && if_push(*stk, hold) == 0)
		r(&stk->b, out);
	return (1);
}

int	rev_checks_rotate(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 0)
		rrr(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 1)
		rrs(&stk->a, out);
	else if (stk->a->num == hold->num && if_push(*stk, hold) == 0)
		rrs(&stk->b, out);
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

int	push_prep_rotate(t_stacks stack, t_node *hold)
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
			rotate += rot_checks_rotate(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	else
	{
		while (old_size == stk.asize)
		{
			rotate += rev_checks_rotate(&stk, hold, 1);
			print_lstnums(stk.a, stk.b);
		}
	}
	stacklst_del(&stk);
	return (rotate);
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
