/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 05:39:20 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-13 05:39:20 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	make_chunk_circle(t_node **lst, t_node **old_next, int chunk)
{
	t_node	*last;

	last = lstlast_chunk(*lst, chunk);
	*old_next = last->next;
	(*lst)->prev = last;
	last->next = *lst;
	return (last->num);
}

void	cut_chunk_circle(t_node **lst, t_node *old_next, int cut)
{
	t_node *head;

	head = *lst;
	if (*lst == NULL)
		return ;
	if ((*lst)->prev->num == cut)
		(*lst)->prev = NULL;
	while (*lst)
	{
		if ((*lst)->num == cut)
		{
			(*lst)->next = old_next;
			*lst = head;
			return ;
		}
		*lst = (*lst)->next;
	}
}

int	make_circle(t_node **lst)
{
	t_node *last;

	last = ft_lstlast(*lst);
	(*lst)->prev = last;
	last->next = *lst;
	return (last->num);
}

void	cut_circle(t_node **lst, int cut)
{
	t_node *head;

	head = *lst;
	if (*lst == NULL)
		return ;
	if ((*lst)->prev->num == cut)
		(*lst)->prev = NULL;
	while (*lst)
	{
		if ((*lst)->num == cut)
		{
			(*lst)->next = NULL;
			*lst = head;
			return ;
		}
		*lst = (*lst)->next;
	}
}
