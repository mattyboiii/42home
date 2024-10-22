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

int	neg_lst(t_node *lst, int chunk)
{
	if (lst == NULL)
		return (0);
	while (lst && lst->chunk == chunk)
	{
		if (lst->num >= 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	chunk_size(t_node *lst, int chunk)
{
	int		i;

	if (lst == NULL)
		return (0);
	if (lst->chunk != chunk)
		return (0);
	i = 1;
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (1);
	while (lst->next && lst->next->chunk == chunk)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_node	*lstlast_chunk(t_node *lst, int chunk)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	if (ft_lstlast(lst)->chunk == chunk && ft_lstlast(lst)->next == NULL)
		return (ft_lstlast(lst));
	while (lst && lst->next->chunk == chunk)
		lst = lst->next;
	return (lst);
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
