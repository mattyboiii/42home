/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 23:12:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-03 23:12:05 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	update_chunk_div(t_node *lst, int chunk_div, int chunk)
{
	t_node *head;

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

t_node	*copy_lst_chunk(t_node **lst, int chunk)
{
	t_node	*head;
	t_node	*copy;

	copy = NULL;
	if (*lst == NULL || lst == NULL)
		return (NULL);
	head = *lst;
	while (*lst && (*lst)->chunk == chunk)
	{
		ft_lstadd_back(&copy, ft_lstnew((*lst)->num, (*lst)->pos,
				(*lst)->stack[0]));
		*lst = (*lst)->next;
	}
	*lst = head;
	return (copy);
}

t_node	*copy_node(t_node *node)
{
	t_node	*copy;

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

t_node	*copy_lst(t_node **lst)
{
	t_node	*head;
	t_node	*copy;

	copy = NULL;
	if (*lst == NULL || lst == NULL)
		return (NULL);
	head = *lst;
	while (*lst)
	{
		ft_lstadd_back(&copy, ft_lstnew((*lst)->num, (*lst)->pos,
				(*lst)->stack[0]));
		if (copy == NULL)
			return (NULL);
		copy->chunk = (*lst)->chunk;
		*lst = (*lst)->next;
	}
	*lst = head;
	return (copy);
}

t_node	*sorted_chunk(t_node *a, t_node *s_chunk, int chunk, int chunk_div)
{
	if (!s_chunk || s_chunk->chunk != chunk)
		ft_lstclear(&s_chunk);
	while (a)
	{
		if (a->num <= chunk_div)
		{
			ft_lstadd_back(&s_chunk, ft_lstnew(a->num, a->pos, a->stack[0]));
			ft_lstlast(s_chunk)->chunk = chunk;
		}
		a = a->next;
	}
	s_chunk = simple_sort(s_chunk);
	return (s_chunk);
}
