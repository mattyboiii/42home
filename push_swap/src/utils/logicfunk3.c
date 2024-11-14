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
			if (node->chunk != chunk && node->next != NULL)
				node = node->next;
			if (node && node->num < compare)
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

int	get_chunk_number(t_node *lst)
{
	int		chunk_step;
	t_node	*big;
	t_node	*small;

	set_big_small(&lst, &big, &small);
	if (ft_lstlast(lst)->pos <= 99)
		chunk_step = ((big->num - small->num) / 5);
	if (ft_lstlast(lst)->pos > 99)
		chunk_step = ((big->num - small->num) / 12);
	return (chunk_step);
}

t_node	*hold_first(t_node *lst, int chunk_div, int future)
{
	int		size;

	size = ft_lstlast(lst)->pos / 2;
	while (lst && lst->pos <= size)
	{
		if (lst->num <= chunk_div && future)
			future--;
		else if (lst->num <= chunk_div && !future)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_node	*hold_second(t_node *lst, int chunk_div, int future)
{
	int		size;

	lst = ft_lstlast(lst);
	size = ft_lstlast(lst)->pos / 2;
	while (lst && lst->pos > size)
	{
		if (lst->num <= chunk_div && future)
			future--;
		else if (lst->num <= chunk_div)
			return (lst);
		lst = lst->prev;
	}
	return (NULL);
}

