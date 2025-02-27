/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_list_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:03:39 by mexuCharlie       #+#    #+#             */
/*   Updated: 2024/10/30 16:48:44 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	d_list_iter(t_dlst *list, void (*f)(void *))
{
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}

// Function to get the last node
t_dlst	*d_list_last(t_dlst *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// Function to get the n-th node
t_dlst	*d_list_get_nth(t_dlst *list, int n)
{
	int	count;

	count = 0;
	if (n < 0)
		return (NULL);
	while (list && count < n)
	{
		list = list->next;
		count++;
	}
	return (list);
}

// Function to copy the list
t_dlst	*d_list_copy(t_dlst *list, void *(*copy)(void *), void (*del)(void *))
{
	t_dlst	*new_list;
	t_dlst	*new_node;

	new_list = NULL;
	while (list)
	{
		new_node = d_list_new(copy(list->content));
		if (!new_node)
		{
			d_list_clear(&new_list, del);
			return (NULL);
		}
		d_list_add_back(&new_list, new_node);
		list = list->next;
	}
	return (new_list);
}

// Function to reverse the list
void	d_list_reverse(t_dlst **list)
{
	t_dlst	*temp;
	t_dlst	*current;

	temp = NULL;
	current = *list;
	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp)
		*list = temp->prev;
}
