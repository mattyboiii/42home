/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:04 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:30:29 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_base *lists)
{
	t_stack_node	*head_a;
	int				numa;
	int				numb;
	int				numc;

	head_a = lists->head_a;
	numa = head_a->data;
	numb = head_a->next->data;
	numc = head_a->next->next->data;
	if (numa > numb && numb < numc && numa < numc)
		swap_sa(head_a);
	else if (numa > numb && numb > numc)
	{
		swap_sa(head_a);
		reverse_rotate_a(lists);
	}
	else if (numa > numc && numb < numc)
		rotate_a(lists);
	else if (numa < numb && numb > numc && numa < numc)
	{
		swap_sa(head_a);
		rotate_a(lists);
	}
	else if (numa < numb && numb > numc && numa > numc)
		reverse_rotate_a(lists);
}

void	sort_five(t_stack_base *lists)
{
	push_b(lists);
	push_b(lists);
	sort_three(lists);
	if (lists->head_b)
		correct_position(lists, lists->head_b->data);
	if (lists->head_b)
		correct_position(lists, lists->head_b->data);
	rotate_until_sorted(lists);
}

void	prepare_stack_a(t_stack_base *lists, int best_number)
{
	t_stack_node	*temp;
	int				size;
	int				index;

	temp = lists->head_a;
	size = stack_size(lists->head_a);
	index = 0;
	while (temp && temp->data != best_number)
	{
		temp = temp->next;
		index++;
	}
	if (index >= size)
		return ;
	if (index <= size / 2)
	{
		while (index-- > 0)
			rotate_a(lists);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			reverse_rotate_a(lists);
	}
}

void	big_sort(t_stack_base *lists)
{
	int				stack_size_a;

	stack_size_a = stack_size(lists->head_a);
	while (stack_size_a > 3)
	{
		push_b(lists);
		stack_size_a = stack_size(lists->head_a);
	}
	sort_three(lists);
	while (lists->head_b)
	{
		set_current_position(lists->head_b);
		set_current_position(lists->head_a);
		find_target(lists->head_a, lists->head_b);
		calculate_push_price(lists->head_a, lists->head_b);
		set_cheapest(lists->head_b);
		push_cheapest(lists);
		if (lists->head_b == NULL)
			break ;
	}
	rotate_until_sorted(lists);
	return ;
}
