/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:13:47 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/29 11:43:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

m_node	*ft_lstnew(int num, int pos)
{
	s_node	*node;

	node = malloc(sizeof(s_node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->pos = pos;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void ft_lstadd_front(s_node **lst, s_node *new)
{
	if (*lst != NULL) {
		(*lst)->prev = new;
	}
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void ft_lstadd_back(s_node **lst, s_node *new)
{
	s_node *last;

	if (*lst == NULL) {
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return;
	}

	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}
