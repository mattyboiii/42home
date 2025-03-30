/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-30 00:45:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025-03-30 00:45:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_mid_up(t_stacks stack, t_node *a, t_node *b)
{
	int		middle;

	middle = stack.asize / 2;
	while (a)
	{
		a->mid_up = (a->pos <= middle);
		a = a->next;
	}
	middle = stack.bsize / 2;
	while (b)
	{
		b->mid_up = (b->pos <= middle);
		b = b->next;
	}
}

void	set_targets(t_node *a, t_node *b)
{
	t_node		*current_b;
	t_node		*compare;
	long		compare_index;

	current_b = b;
	while (current_b)
	{
		compare = a;
		compare_index = LONG_MAX;
		while (compare)
		{
			if (current_b->num < compare->num
				&& compare->num < compare_index)
			{
				compare_index = compare->num;
				current_b->target = compare;
			}
			compare = compare->next;
		}
		if (compare_index == LONG_MAX)
			current_b->target = get_smallest(a);
		current_b = current_b->next;
	}
}

void	set_push_price(t_stacks stack, t_node *b)
{
	while (b)
	{
		b->push_price = b->pos;
		if (b->mid_up == false)
			b->push_price = stack.bsize - b->pos;
		if (b->target->mid_up == true)
			b->push_price += b->target->pos;
		else
			b->push_price += stack.asize - (b->target->pos);
		b = b->next;
	}
}

t_node	*get_cheapest(t_node *b)
{
	t_node		*cheapest;

	if (!b)
		return (NULL);
	cheapest = b;
	while (b)
	{
		if (b->next && b->next->push_price < cheapest->push_price)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void	rot_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		r(lst, print);
		n--;
	}
}

void	rev_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		rrs(lst, print);
		n--;
	}
}


void	force_rot_push(t_stacks *stack, t_node *a, t_node *b, t_node *push)
{
		int		stacksize;

		stacksize = stack->bsize;
		while (stack->bsize == stacksize)
		{
			if (b != push && a != push->target)
				rr(stack, 1);
			else if (b != push && a == push->target)
				r(&b, 1);
			else if (b == push && a != push->target)
				r(&a, 1);
			else if (b == push && a == push->target)
				pa(stack, 1);
			set_mid_up(*stack, a, b);
		}
}

void	force_rev_push(t_stacks *stack, t_node *a, t_node *b, t_node *push)
{
		int		stacksize;

		stacksize = stack->bsize;
		while (stack->bsize == stacksize)
		{
			if (b != push && a != push->target)
				rrr(stack, 1);
			else if (b != push && a == push->target)
				rrs(&b, 1);
			else if (b == push && a != push->target)
				rrs(&a, 1);
			else if (b == push && a == push->target)
				pa(stack, 1);
			set_mid_up(*stack, a, b);
		}
}

void	man_push(t_stacks *stack, t_node *a, t_node *b, t_node *push)
{
	print_stacks(*stack);
	if (a != push->target && push->target->mid_up == true)
		rot_machine(&a, push->target->pos, 1);
	else if (a != push->target && push->target->mid_up == false)
		rev_machine(&a, stack->asize - push->target->pos, 1);
	print_stacks(*stack);
	if (b != push && push->target->mid_up == true)
		rot_machine(&b, push->target->pos, 1);
	else if (b != push->target && push->target->mid_up == false)
		rev_machine(&b, push->target->pos, 1);
	pa(stack, 1);
	set_mid_up(*stack, a, b);
}

void	push_cheapest(t_stacks *stack, t_node **a, t_node **b, t_node *cheap)
{
	if (cheap->mid_up && cheap->target->mid_up)
		force_rot_push(stack, *a, *b, cheap);
	else if (!cheap->mid_up && !cheap->target->mid_up)
		force_rev_push(stack, *a, *b, cheap);
	else
		man_push(stack, *a, *b, cheap);
}

void	sort(t_stacks *stack)
{
	t_node		*cheap;

	while (stack->asize > 3)
		pb(stack, 1);
	sort3(&stack->a);
	while (stack->b)
	{
		print_stacks(*stack);
		set_mid_up(*stack, stack->a, stack->b);
		set_targets(stack->a, stack->b);
		set_push_price(*stack, stack->b);
		cheap = get_cheapest(stack->b);
		push_cheapest(stack, &stack->a, &stack->b, cheap);
		print_stacks(*stack);
	}
}
