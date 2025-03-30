/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:22 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:18:30 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack_node	*smallest_node(t_stack_node *head)
{
	t_stack_node	*smallest;

	if (head == NULL)
		return (NULL);
	smallest = head;
	while (head != NULL)
	{
		if (head->data < smallest->data)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

void	find_target_node(t_stack_node *head_a, t_stack_node *head_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (head_b)
	{
		best_match_index = LONG_MAX;
		current_a = head_a;
		while (current_a)
		{
			if ((current_a->data > head_b->data)
				&& (current_a->data < best_match_index))
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			head_b->target_node = smallest_node(head_a);
		else
			head_b->target_node = target_node;
		head_b = head_b->next;
	}
}

void	calculate_push_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}
