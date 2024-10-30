/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-30 02:28:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-30 02:28:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_lg_sm(t_node *lst, int compare, int chunk, int lg_sm)
{
	t_node	*node;

	node = lst;
	if (lg_sm == 0)
	{
		while (node)
		{
			if (node->chunk != chunk)
				node = node->next;
			if (node->num < compare)
				return (1);
			node = node->next;
		}
	}
	else
	{
		while (node)
		{
			if (node->num > compare)
				return (1);
			node = node->next;
		}
	}
	return (0);
}

t_node	*get_midnode(t_node **lst, int chunk)
{
	t_node	*sorted;
	t_node	*midnode;
	t_node	*last;
	t_node	*out;

	sorted = NULL;
	out = *lst;
	if (chunk_size(*lst, chunk) <= 2 || (*lst)->next == NULL)
		return (*lst);
	sorted = simple_sort(copy_lst(lst, chunk));
	last = ft_lstlast(sorted);
	midnode = get_node(sorted, (last->pos + 1) / 2);
	while (out && out->num != midnode->num)
		out = out->next;
	ft_lstclear(&sorted);
	last = NULL;
	midnode = NULL;
	return (out);
}
