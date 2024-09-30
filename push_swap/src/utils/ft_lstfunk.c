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

t_node	*ft_lstlast(t_node *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstnew(int num, int pos)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->pos = pos;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (*lst != NULL)
	{
		(*lst)->prev = new;
	}
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}

int	ft_lstsize(t_node *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
