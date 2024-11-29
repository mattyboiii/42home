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

/* force_rotate_check - assymilates using the force logic but with copied stacks,
using the hold which is being tested. None of the changes made will be applied yet
the actions will simply be counted and returned for comparison later.
*/
int	force_rotate_check(t_stacks stack, t_node *hold, int rotate)
{
	int			old_size;
	int			operations;
	t_stacks	stk;

	stk = stacklst_dup(stack);
	operations = 0;
	old_size = stk.asize;
	if (rotate >= 0)
	{
		while (old_size == stk.asize)
		{
			operations += rot_checks_rotate(&stk, hold, 0);
			if (stack.asize <= 2)
				print_stacks(stk);
		}
	}
	else
	{
		while (old_size == stk.asize)
			operations += rev_checks_rotate(&stk, hold, 0);
	}
	stacklst_del(&stk);
	return (operations);
}

/* rotate_run - is the same as force_rotate_check, but it uses the real stacks.
this is because all calculations have been done and the current hold will yeild
the leat amount of operations
*/
int	rotate_run(t_stacks *stack, t_node *hold, int rotate)
{
	int		old_size;
	int		operations;

	operations = 0;
	old_size = stack->asize;
	if (rotate >= 0)
	{
		while (old_size == stack->asize)
			operations += rot_checks_rotate(stack, hold, 1);
	}
	else
	{
		while (old_size == stack->asize)
			operations += rev_checks_rotate(stack, hold, 1);
	}
	return (operations);
}
