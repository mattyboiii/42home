/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:48:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_head(t_node *lst)
{
	t_node *head;

	if (lst == NULL)
		return (NULL);
	head = lst;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}

t_node	*fill_a(char **arv)
{
	int			i;
	int			j;
	t_node		*lst;
	t_node		*node;

	i = 0;
	j = 0;
	lst = NULL;
	while (arv[i] && arv[i + j])
	{
		if (arv[i][0] == '/')
		{
			node = ft_lstnew(ft_atoi(arv[i + 1]), i, 'a');
			j++;
		}
		else
			node = ft_lstnew(ft_atoi(arv[i + j]), i, 'a');
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

void	ft_stackposupdate(t_node *node)
{
	int		i;

	if (node == NULL)
		return ;
	if (node->pos > 0 && node->prev != NULL)
		i = node->pos;
	else
		i = 0;
	while (node)
	{
		node->pos = i;
		i++;
		node = node->next;
	}
}
/*
nodedel returns the deleted node.
the list is updated to simpy forget the node variable ever existed.
it does not actually do any deleting/freeing of memory.
*/

t_node	*ft_nodedel(t_node *node)
{
	t_node	*nnex;
	t_node	*npre;
	t_node	*chopped;

	if (node == NULL)
		return (NULL);
	nnex = NULL;
	npre = NULL;
	if (node->prev != NULL)
	{
		npre = node->prev;
		npre->next = node->next;
	}
	if (node->next != NULL)
	{
		nnex = node->next;
		nnex->prev = node->prev;
	}
	chopped = node;
	if (node->prev == NULL)
		node = nnex;
	else
		node = npre;
	ft_stackposupdate(node);
	return (chopped);
}

t_node	*ft_quicksort(t_node *lst)
{
	t_node		*i;
	t_node		*j;
	t_node		*pivot;

	while (


}
