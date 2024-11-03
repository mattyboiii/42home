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
		*lst = (*lst)->next;
	}
	*lst = head;
	return (copy);
}
