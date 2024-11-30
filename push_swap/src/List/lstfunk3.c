/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-30 00:19:42 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	update_chunk_div(t_node *lst, int chunk_div, int chunk)
{
	t_node		*head;

	if (!lst)
		return (-1);
	while (lst)
	{
		lst->chunk = chunk;
		lst->div = chunk_div;
		lst = lst->next;
	}
	return (1);
}

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
	ft_lstadd_front(&copy, ft_lstnew(node->num, node->pos,
			node->stack[0]));
	if (!copy)
		return (NULL);
	copy->chunk = node->chunk;
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
		ft_lstadd_back(&copy, ft_lstnew(lst->num, lst->pos,
				lst->stack[0]));
		ft_lstlast(copy)->chunk = lst->chunk;
		ft_lstlast(copy)->div = lst->div;
		lst = lst->next;
	}
	return (copy);
}
