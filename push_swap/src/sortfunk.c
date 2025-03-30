/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:25:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_des(t_node *lst)
{
	lst = ft_lstlast(lst);
	if (lst == NULL)
		return (1);
	while (lst->prev != NULL)
	{
		if (lst->prev->num < lst->num)
			return (0);
		lst = lst->prev;
	}
	return (1);
}

int	sorted_asc(t_node *lst, t_node *start)
{
	t_node	*head;

	head = lst;
	while (lst != start)
		lst = lst->next;
	while (lst->next != NULL)
	{
		if (lst->num > lst->next->num)
		{
			lst = head;
			return (0);
		}
		lst = lst->next;
	}
	lst = head;
	return (1);
}

void	numswap(t_node *bigger, t_node *smaller)
{
	int		swap;

	swap = bigger->num;
	bigger->num = smaller->num;
	smaller->num = swap;
}

t_node	*simple_sort(t_node *lst)
{
	t_node	*current;
	t_node	*next_node;
	t_node	*head;

	head = lst;
	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->num > next_node->num)
				numswap(current, next_node);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (head);
}
