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

int	rot_checks(t_stacks *stack, t_node *hold, int div)
{
	if (stack->a->num <= div && if_push(*stack, stack->a) == 1)
	{
		pb(stack, 1);
		return (1);
	}
	else if (stack->a->next->num <= div && if_push(*stack, stack->a->next) == 1)
		s(&stack->a, 1);
	else if (if_push(*stack, hold) == 1)
		r(&stack->a, 1);
	else if (stack->a->num > div)
		rr(stack);
	else if (stack->a->next->num <= div && if_push (*stack, stack->a) == 0)
		r(&stack->b, 1);
	else if (stack->a->num <= div && if_push(*stack, stack->a) == 0)
	{
		s(&stack->a, 1);
		rr(stack);
	}
	else
		r(&stack->a, 1);
	return (0);
}

int	rev_checks(t_stacks *stack, t_node *last, t_node *hold, int div)
{
	if (stack->a->num <= div && if_push(*stack, stack->a) == 1)
	{
		pb(stack, 1);
		return (1);
	}
	else if (last->num <= div && if_push(*stack, last) == 1)
		rrs(&stack->a, 1);
	else if (stack->a->num > div)
		rrr(stack);
	else if (last->num <= div && if_push(*stack, stack->a) == 0)
		rrs(&stack->b, 1);
	else if (stack->a->num <= div && if_push(*stack, stack->a) == 0)
		s(&stack->a, 1);
	else
		rrs(&stack->a, 1);
	return (0);
}

void	push_prep(t_stacks stack, t_node *hold, int rotate)
{
	int		old_size;
	t_node	*last;

	old_size = stack.asize;
	if (rotate > 0)
	{
		while (stack.asize == old_size)
			rot_checks(&stack, hold, stack.a->div);
	}
	else
	{
		while (old_size == stack.asize)
		{
			last = ft_lstlast(stack.a);
			rev_checks(&stack, last, hold, stack.a->div);
			print_lstnums(stack.a, stack.b);
		}
	}
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
