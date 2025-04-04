/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:19:37 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 14:02:16 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_base *lists)
{
	t_stack_node	*temp_head;
	t_stack_node	*tail;

	temp_head = lists->head_a;
	tail = lists->head_a;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = temp_head;
	lists->head_a = temp_head->next;
	temp_head->next = NULL;
	ft_putstr("ra\n");
}

void	rotate_b(t_stack_base *lists)
{
	t_stack_node	*temp_head;
	t_stack_node	*current;

	temp_head = lists->head_b;
	current = lists->head_b;
	if (!lists->head_b || !lists->head_b->next)
		return ;
	lists->head_b = temp_head->next;
	while (current->next)
		current = current->next;
	current->next = temp_head;
	temp_head->next = NULL;
	ft_putstr("rb\n");
}

void	reverse_rotate_b(t_stack_base *lists)
{
	t_stack_node	*tail;
	t_stack_node	*before_tail;

	before_tail = NULL;
	tail = lists->head_b;
	if (!lists->head_b || !lists->head_b->next)
		return ;
	while (tail->next)
	{
		before_tail = tail;
		tail = tail->next;
	}
	tail->next = lists->head_b;
	before_tail->next = NULL;
	lists->head_b = tail;
	ft_putstr("rrb\n");
}
