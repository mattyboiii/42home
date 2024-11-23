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

int	rot_checks(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
	{
		pb(stk, out);
		return (1);
	}
	else if (stk->a->next->num <= stk->a->div && stk->a->num <= stk->a->div
			&& if_push(*stk, stk->a->next) == 1)
		s(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 0)
		rr(stk);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else
		r(&stk->a, out);
	return (0);
}

int	rev_checks(t_stacks *stk, t_node *last, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
	{
		pb(stk, out);
		return (1);
	}
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
	return (0);
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
void	push_prep(t_stacks *stack, t_node *hold, int rotate)
{
	int		old_size;
	t_node	*last;

	old_size = stack->asize;
	if (rotate >= 0)
	{
		while (old_size == stack->asize)
		{
			rot_checks(stack, hold, stack->a->div);
			print_lstnums(stack->a, stack->b);
		}
	}
	else
	{
		while (old_size == stack->asize)
		{
			last = ft_lstlast(stack->a);
			rev_checks(stack, last, hold, stack->a->div);
			print_lstnums(stack->a, stack->b);
		}
	}
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
