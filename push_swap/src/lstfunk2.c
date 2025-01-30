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

void	fill_a(t_stacks *stack, char **arv)
{
	int			i;
	t_node		*node;

	i = 0;
	if (arv[0][0] == '/' || arv[0][0] == '.')
		i = 1;
	node = NULL;
	while (arv[i])
	{
		node = ft_lstnew(ft_atoi(arv[i]), 'a');
		if (node == NULL)
			return ;
		ft_lstadd_back(&stack->a, node);
		i++;
	}
	ft_stackposupdate(stack->a);
	stack->asize = ft_lstlast(stack->a)->pos + 1;
	stack->bsize = 0;
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

void	ft_lstclear(t_node **lst)
{
	t_node	*node;

	if (!(*lst) || !(*lst))
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = node;
	}
	*lst = NULL;
}

// nodedel returns the deleted node.
// the list is updated to simply forget the node variable ever existed.
// it does not actually do any deleting/freeing of memory.
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
