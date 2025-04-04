/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:30:34 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** removing this function because I have changed how the chunk_div is updated
int	update_chunk_div(t_stack *stack, int chunk_div, int chunk)
{
	if (!stack)
		return (-1);
	while (stack)
	{
		stack->chunk = chunk;
		stack->div = chunk_div;
		stack = lst->next;
	}
	return (1);
}
*/

t_node	*get_node(t_node *lst, int index)
{
	t_node		*node;

	node = lst;
	if (lst == NULL)
		return (NULL);
	while (node->pos < index && node->next != NULL)
		node = node->next;
	return (node);
}

t_node	*copy_node(t_node *node)
{
	t_node		*copy;

	copy = NULL;
	if (!node)
		return (NULL);
	ft_lstadd_front(&copy, ft_lstnew(node->num, node->stack[0]));
	if (!copy)
		return (NULL);
	copy->chunk = node->chunk;
	copy->pos = node->pos;
	copy->prev = NULL;
	copy->next = NULL;
	return (copy);
}

t_node	*copy_lst(t_node *lst)
{
	t_node	*copy;

	copy = NULL;
	if (lst == NULL || lst == NULL)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&copy, ft_lstnew(lst->num, lst->stack[0]));
		ft_lstlast(copy)->chunk = lst->chunk;
		lst = lst->next;
	}
	ft_stackposupdate(copy);
	return (copy);
}
