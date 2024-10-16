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

t_node	*ft_lstlast(t_node *lst)
{
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
	node->head = NULL;
	node->foot = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = NULL;
	new->prev = NULL;
	new->head = &new;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
		new->foot = (*lst)->foot;
		(*lst)->head = lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->head = &new;
		new->prev = NULL;
		new->next = NULL;
		new->head = lst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
	new->head = (*lst)->head;
	new->foot = &new;
	(*lst)->foot = &new;
}


/*
t_node	*copy_addback(t_node **lst, t_node *node)
{
	t_node	*dupnode;

	if (node == NULL)
		return (NULL);
	dupnode->num = node->num;
	dupnode->pos = node->pos;
	*(dupnode)->stack = *(node)->stack;
	ft_lstadd_back(lst, dupnode);
	ft_stackposupdate(*lst);
	return (*lst);
}
*/
/*
int	ft_lstsize(t_node *lst)
{
	int	len;

	len = 0;
	while (lst)gT
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
*/
