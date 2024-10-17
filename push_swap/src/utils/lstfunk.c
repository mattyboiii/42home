/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:25 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:48:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = NULL;
	new->prev = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
		*lst = new;
	}
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

t_node	*ft_lstlast(t_node *lst)
{
	if (lst->next == NULL)
		return (lst);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstnew(int num, int pos, char c)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->pos = pos;
	node->stack[0] = c;
	node->stack[1] = '\0';
	node->next = NULL;
	node->prev = NULL;
	node->chunk = 0;
	return (node);
}
t_node	*copy_lst(t_node **lst, int	chunk)
{
	t_node	*head;
	t_node	*copy;

	copy = NULL;
	if (*lst == NULL || lst == NULL)
		return (NULL);
	head = *lst;
	while (*lst && (*lst)->chunk == chunk)
	{
		ft_lstadd_back(&copy, ft_lstnew((*lst)->num, (*lst)->pos, (*lst)->stack[0]));
		*lst = (*lst)->next;
	}
	*lst = head;
	return(copy);
}
