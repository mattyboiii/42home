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

int	if_swap(t_node *lst, int chunk, int descending)
{
	int		ret;

	ret = 0;
	if (lst->chunk != lst->next->chunk)
		return (0);
	numswap(lst, lst->next);
	if (descending == 1)
	{
		if (sorted_des(lst, chunk) == 1)
			ret = 1;
		else
			ret = 0;
		numswap(lst, lst->next);
		return (ret);
	}
	else
	{
		if (sorted_asc(lst, lst, chunk) == 1)
			ret = 1;
		else
			ret = 0;
		numswap(lst, lst->next);
		return (ret);
	}
}

t_node	*get_node(t_node *lst, int index)
{
	t_node	*node;

	node = lst;
	if (lst == NULL)
		return (NULL);
	while (node->pos < index && node->next != NULL)
		node = node->next;
	return (node);
}
