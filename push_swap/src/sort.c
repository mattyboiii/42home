/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-30 00:45:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/04/01 09:13:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_mid_h(t_stacks *stack)
{
	int middle;
	t_node *current_b = stack->b;
	t_node *current_a = stack->a;

	middle = stack->asize / 2;
	while (current_a) {
		current_a->mid_h = (current_a->pos <= middle);
		current_a = current_a->next;
	}
	middle = stack->bsize / 2;
	while (current_b) {
		current_b->mid_h = (current_b->pos <= middle);
		current_b = current_b->next;
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
		b->push_price++;
		b = b->next;
	}
}

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
		if (b && (b->push_price <= cheapest->push_price &&
					(b->num > 0 && cheapest->num < 0) ||
					b->num > cheapest->num))
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void    sort(t_stacks *stack)
{
	t_node      *cheap;
	int         debug = 0;

	while (stack->asize > 3)
		pb(stack, 1);
	sort3(&stack->a);
	while (stack->b)
	{
		set_mid_h(stack);
		set_targets(stack->a, stack->b);

		if (debug && stack->b->num == 100)
			printf(" ");

		set_push_price(stack);

		if (debug && stack->b->num == 83)
			printf(" ");

		cheap = get_cheapest(stack->b);

		if (debug)
		{
			printf("Cheap: %ld\n", cheap->num);
			printf("Targt: %ld\n", cheap->target->num);
			printf("Ch-pp: %d\n", cheap->push_price);
			print_stacks(stack);
		}

		push_cheapest(stack, cheap);
	}
	smallest_on_top(stack);

	if (debug)
	{
		if (sorted_asc(stack->a, stack->a) == 1)
			ft_printf("sorted\n");
		print_stacks(stack);
	}
}

