/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:00 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:18:31 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(int data)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	append(t_stack_node **head, int data)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = create_node(data);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	print_stack(t_stack_node *head, char stack_name)
{
	printf("Stack %c: ", stack_name);
	while (head)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void	free_stack(t_stack_node *head)
{
	t_stack_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	size;
	int	centerline;

	i = 0;
	size = stack_size(stack);
	centerline = size / 2;
	while (stack)
	{
		stack->current_position = i;
		stack->above_median = (i <= centerline);
		stack = stack->next;
		++i;
	}
}
