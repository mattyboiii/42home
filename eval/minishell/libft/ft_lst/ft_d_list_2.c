/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexuCharlie <charlie_xumeng@hotmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:56:50 by mexuCharlie       #+#    #+#             */
/*   Updated: 2024/11/04 22:54:18 by mexuCharlie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	d_list_add_back(t_dlst **list, t_dlst *new_node)
{
	t_dlst	*last;

	if (!list || !new_node)
		return ;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

// Function to add a node to the front
void	d_list_add_front(t_dlst **list, t_dlst *new_node)
{
	if (!list || !new_node)
		return ;
	new_node->next = *list;
	new_node->prev = NULL;
	if (*list)
		(*list)->prev = new_node;
	*list = new_node;
}

// Function to remove nodes by content
void	d_list_remove_if(t_dlst **list, void *content,
		int (*cmp)(void *, void *), void (*del)(void *))
{
	t_dlst	*current;
	t_dlst	*next_node;

	current = *list;
	while (current)
	{
		next_node = current->next;
		if (cmp(current->content, content) == 0)
			d_list_delone(current, del);
		current = next_node;
	}
}

// Function to delete one node
void	d_list_delone(t_dlst *node, void (*del)(void *))
{
	if (!node)
		return ;
	if (del)
		del(node->content);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	ft_free(node);
}

// Function to clear the list
void	d_list_clear(t_dlst **list, void (*del)(void *))
{
	t_dlst	*current;
	t_dlst	*next_node;

	current = *list;
	while (current)
	{
		next_node = current->next;
		if (del)
			del(current->content);
		ft_free(current);
		current = next_node;
	}
	*list = NULL;
}
