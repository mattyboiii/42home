/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:19:13 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:19:41 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	push_b(t_stack_base *lists)
{
	push(&lists->head_a, &lists->head_b);
	ft_putstr("pb\n");
}

void	push_a(t_stack_base *lists)
{
	push(&lists->head_b, &lists->head_a);
	ft_putstr("pa\n");
}

void	swap_sa(t_stack_node *head)
{
	int	temp;

	if (!head || !head->next)
		return ;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	ft_putstr("sa\n");
}

void	reverse_rotate_a(t_stack_base *lists)
{
	t_stack_node	*tail;
	t_stack_node	*before_tail;

	before_tail = NULL;
	tail = lists->head_a;
	if (!lists->head_a || !lists->head_a->next)
		return ;
	while (tail->next)
	{
		before_tail = tail;
		tail = tail->next;
	}
	tail->next = lists->head_a;
	before_tail->next = NULL;
	lists->head_a = tail;
	ft_putstr("rra\n");
}
