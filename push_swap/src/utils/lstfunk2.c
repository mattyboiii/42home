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
