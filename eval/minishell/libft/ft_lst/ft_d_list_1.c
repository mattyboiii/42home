/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_list_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:56:24 by mexuCharlie       #+#    #+#             */
/*   Updated: 2024/11/07 09:57:47 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to create a new node
t_dlst	*d_list_new(void *content)
{
	t_dlst	*new_node;

	new_node = malloc(sizeof(t_dlst));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// Function to get the first node
t_dlst	*d_list_first(t_dlst *list)
{
	return (list);
}

// Function to get the second node
t_dlst	*d_list_second(t_dlst *list)
{
	if (list && list->next)
		return (list->next);
	return (NULL);
}

// Function to find a node by content
t_dlst	*d_list_find(t_dlst *list, void *content, int (*cmp)(void *, void *))
{
	while (list)
	{
		if (cmp(list->content, content) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
