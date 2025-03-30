/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:11 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:29:57 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rr(t_stack_base *lists)
{
	t_stack_node	**heads[2];
	t_stack_node	*temp;
	t_stack_node	*tail;
	int				i;

	heads[0] = &lists->head_a;
	heads[1] = &lists->head_b;
	i = 0;
	while (i < 2)
	{
		if (*heads[i] && (*heads[i])->next)
		{
			temp = *heads[i];
			*heads[i] = (*heads[i])->next;
			temp->next = NULL;
			tail = *heads[i];
			while (tail->next)
				tail = tail->next;
			tail->next = temp;
		}
		i++;
	}
	ft_putstr("rr\n");
}

static void	reverse_rotate_stack(t_stack_node **head)
{
	t_stack_node	*tail;
	t_stack_node	*prev;

	if (!*head || !(*head)->next)
		return ;
	tail = *head;
	prev = NULL;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *head;
	*head = tail;
}

void	rrr(t_stack_base *lists)
{
	t_stack_node	**heads[2];
	int				i;

	heads[0] = &lists->head_a;
	heads[1] = &lists->head_b;
	i = 0;
	while (i < 2)
	{
		reverse_rotate_stack(heads[i]);
		i++;
	}
	ft_putstr("rrr\n");
}
