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

int		if_swap(t_node *lst, int chunk)
{
	numswap(lst, lst->next);
	if (sorted_des(lst, chunk) == 1)
	{
		numswap(lst, lst->next);
		return (1);
	}
	else
	{
		numswap(lst, lst->next);
		return (0);
	}
}

int		chunk_size(t_node *lst, int chunk)
{
	int		i;

	i = 0;
	{
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
}
t_node	*lstlast_chunk(t_node *lst, int	chunk)
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


