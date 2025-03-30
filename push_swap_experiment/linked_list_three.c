/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:16:29 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 15:16:39 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b_to_top(t_stack_base *lists, int position, int size)
{
	t_stack_node	*temp;

	temp = lists->head_b;
	if (position == 0)
		return ;
	if (temp->above_median == true)
	{
		while (position > 0)
		{
			rotate_b(lists);
			position--;
		}
	}
	else
	{
		while (position <= size)
		{
			reverse_rotate_b(lists);
			position++;
		}
	}
}

void	rotate_target_to_top(t_stack_base *lists, t_stack_node *target)
{
	int	size;
	int	pos;
	int	i;

	size = stack_size(lists->head_a);
	pos = target->current_position;
	i = 0;
	if (pos == 0)
		return ;
	if (target->above_median)
	{
		while (i < pos)
		{
			rotate_a(lists);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			reverse_rotate_a(lists);
			i++;
		}
	}
}

void	set_cheapest(t_stack_node *head)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*current;

	cheapest_node = head;
	current = head->next;
	cheapest_node = head;
	current = head->next;
	if (head == NULL)
		return ;
	while (current != NULL)
	{
		if (current->push_price < cheapest_node->push_price)
			cheapest_node = current;
		current = current->next;
	}
	cheapest_node->cheapest = true;
}
