/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-30 00:45:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/04/01 14:45:40 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief loops through both stacks applying true/false to the value mid_h
 * based on position. h = "higher". So if the node is in the middle, or higher
 * than the middle, mid_h = true. In the example below, you will notice that
 * if the stack is odd numbered in legnth. There will still be more "true"
 * than "false".
 * pos 0: = true
 * pos 1: = true
 * pos 2: = false.
 */
void	set_mid_h(t_stacks *stack)
{
	int			middle;
	t_node		*current_a;
	t_node		*current_b;

	current_a = stack->a;
	current_b = stack->b;
	middle = stack->asize / 2;
	while (current_a)
	{
		current_a->mid_h = (current_a->pos <= middle);
		current_a = current_a->next;
	}
	middle = stack->bsize / 2;
	while (current_b)
	{
		current_b->mid_h = (current_b->pos <= middle);
		current_b = current_b->next;
	}
}

/**
 * @brief set_targets loops through stack b, comparing current
 * number to every number in stack a. A target is the number
 * which is the closest without being equal. If b->num = 3, the
 * best target is 4.
 */
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

/**
 * @brief set_push_price loops through stack->b and calculates a push
 * price based on the nodes position and target nodes position. It
 * also checks the b->mid_h and b->target->mid_h. As if they
 * are both the same value, and not the top or bottom number, it will
 * run set_rr_rr_push_price. That way the push_price logic considers
 * using rr or rrr. push_price is used by get_cheapest to calculate
 * the mose efficient node to push.
 */
void	set_push_price(t_stacks *stack)
{
	t_node		*b;

	b = stack->b;
	while (b)
	{
		b->push_price = b->pos;
		if (b->mid_h == false)
			b->push_price = stack->bsize - b->pos;
		if (b->target->mid_h == true)
			b->push_price += b->target->pos;
		else
			b->push_price += stack->asize - (b->target->pos);
		if (b->mid_h == false && b->target->mid_h == false && b->pos > 0
			&& b->pos + 1 != stack->bsize && b->target->pos > 0
			&& b->target->pos + 1 != stack->asize)
			set_rr_rrr_push_price(*stack, b);
		if (b->mid_h == true && b->target->mid_h == true && b->pos > 0
			&& b->pos + 1 != stack->bsize && b->target->pos > 0
			&& b->target->pos + 1 != stack->asize)
			set_rr_rrr_push_price(*stack, b);
		b->push_price++;
		b = b->next;
	}
}

/**
 * @brief cheapest will take in a stack, compare the nodes push_price
 * and number, to return the node whos push_price is cheapest. This
 * function also allows me to change preferences in the situation
 * where many nodes push_price is the same.
 * Preferences are below:
 * 1. higher up
 * 2. Cheapest push_price
 * 3. Number is a positive number
 * 4. Number is greater
 *
 * @return node which has the most amount of preferences
 */
t_node	*get_cheapest(t_node *b)
{
	t_node		*cheapest;

	if (!b)
		return (NULL);
	if (b->next == NULL)
		return (b);
	cheapest = b;
	while (b)
	{
		if (b->num == 52)
			printf(" ");
		if (((b && (b->push_price < cheapest->push_price))
				|| ((b->push_price <= cheapest->push_price)
					&& ((b->num > 0 && cheapest->num < 0)
						|| b->num > cheapest->num))))
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

/**
 * @brief sort, is responsible for running all functions which will
 * be used to eventually sort the stacks. After sort is finished the
 * stacks will be sorted.
 */
void	sort(t_stacks *stack)
{
	t_node		*cheap;

	while (stack->asize > 3)
		pb(stack, 1);
	sort3(&stack->a);
	while (stack->b)
	{
		set_mid_h(stack);
		set_targets(stack->a, stack->b);
		set_push_price(stack);
		cheap = get_cheapest(stack->b);
		push_cheapest(stack, cheap);
	}
	smallest_on_top(stack);
}
