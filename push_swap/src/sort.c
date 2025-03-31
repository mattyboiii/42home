/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-30 00:45:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/03/30 20:12:09 by mtripodi         ###   ########.fr       */
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
		if (b && (b->push_price < cheapest->push_price ||
			(b->push_price <= cheapest->push_price && b->num > 0
				&& cheapest->num < 0)))
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
void force_rot_push(t_stacks *stack, t_node *push)
{
	int stacksize = stack->bsize;

	while (stack->bsize == stacksize) {
		if (stack->b != push && stack->a != push->target)
			rr(stack, 1);
		else if (stack->b != push && stack->a == push->target)
			r(&(stack->b), 1);
		else if (stack->b == push && stack->a != push->target)
			r(&(stack->a), 1);
		else if (stack->b == push && stack->a == push->target)
			pa(stack, 1);

		set_mid_h(stack); // Update mid_h flags globally
	}
}

void	force_rev_push(t_stacks *stack, t_node *push)
{
	int		stacksize;

	stacksize = stack->bsize;
	while (stack->bsize == stacksize)
	{
		if (stack->b != push && stack->a != push->target)
			rrr(stack, 1);
		else if (stack->b != push && stack->a == push->target)
			rrs(&(stack->b), 1);
		else if (stack->b == push && stack->a != push->target)
			rrs(&(stack->a), 1);
		else if (stack->b == push && stack->a == push->target)
			pa(stack, 1);
		set_mid_h(stack);
	}
}

void	man_push(t_stacks *stack, t_node *push)
{
	if (stack->a != push->target && push->target->mid_h == true)
		rot_machine(&(stack->a), push->target->pos, 1);
	else if (stack->a != push->target && push->target->mid_h == false)
		rev_machine(&(stack->a), stack->asize - push->target->pos, 1);
	set_mid_h(stack);
	if (stack->b != push && push->mid_h == true)
		rot_machine(&(stack->b), push->pos, 1);
	else if (stack->b != push->target && push->mid_h == false)
		rev_machine(&(stack->b), stack->bsize - push->pos, 1);
	pa(stack, 1);
	set_mid_h(stack);
}

void	push_cheapest(t_stacks *stack, t_node *cheap)
{
	if (cheap->mid_h == true && cheap->target->mid_h == true)
		force_rot_push(stack, cheap);
	else if (cheap->mid_h == false && cheap->target->mid_h == false)
		force_rev_push(stack, cheap);
	else
		man_push(stack, cheap);
}

void	smallest_on_top(t_stacks *stack)
{
	t_node		*small;

	set_big_small(stack->a, 0, &small);
	while (stack->a != small)
	{
		if (small->mid_h == true)
			rot_machine(&(stack->a), small->pos, 1);
		else
			rev_machine(&(stack->a), stack->asize - small->pos, 1);
	}
}
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
		// if (stack->b->num == 100)
		// 	printf(" ");
		set_push_price(stack);
		// if (stack->b->num == 83)
		// 	printf(" ");
		cheap = get_cheapest(stack->b);
		// printf("Cheap: %ld\n", cheap->num);
		// printf("Targt: %ld\n", cheap->target->num);
		// printf("Ch-pp: %d\n", cheap->push_price);
		// print_stacks(stack);
		push_cheapest(stack, cheap);
	}
	smallest_on_top(stack);
	// if (sorted_asc(stack->a, stack->a) == 1)
	// 	ft_printf("sorted\n");
	// print_stacks(stack);
}
