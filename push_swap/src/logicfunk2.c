/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:59:11 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:29:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief this function is responsible for setting the chunk divider. It will
 * seperate the stacks based on size of the largest value in the
 * stack - smallest. Depending on the toatl size, it will then divide it into
 * 5 chunks, or 11;
 *
 * @return int chunk_divider
		chunk_step = ((big->num - small->num) / 11);
	if (stack.asize > 120)
		chunk_step = ((big->num - small->num) / 20);
 */
int	get_chunk_number(t_stacks stack)
{
	int		chunk_step;
	t_node	*big;
	t_node	*small;

	set_big_small(stack.a, &big, &small);
	if (stack.asize <= 99)
		chunk_step = ((big->num - small->num) / 5);
	if (stack.asize > 99)
		chunk_step = ((big->num - small->num) / 11);
	return (chunk_step);
}

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

/** UPDATED - 07.03.25
 * @brief closest hold simply applys the node whos number is <= divider, to
 * hold_a or hold_b, depending on their position.
 *
 * If its in the first half of the stack, it will go to hold_a, if
 * its in the second half of the stack it will belong to hold_b. The
 * future, simply allows me to skip over however many node's which apply
 * to the <= divider logic. In case the number after the closest allows
 * for less operations when sending it to b/
 *
 * update - it now also runs the pos_greater_than_ops function. If the
 * function returns a 1, it will set that hold to NULL. so the loop skips
 * it making it more efficient.
 *
 * update - This change cuased errors. Untill I smooth them out, the addition
 * wont be used.
*/
int	closest_hold(t_stacks stack, t_hold *hold, int future)
{
	hold->fh = hold_first(stack, stack.div, future);
	hold->sh = hold_second(stack, stack.div, future);
	/*
	if (pos_greater_than_ops(*hold, *hold->fh) == 1)
		hold->fh = NULL;
	if (pos_greater_than_ops(*hold, *hold->sh) == 1)
		hold->fh = NULL;
	 
	*/
	return (0);
}

t_node	*hold_first(t_stacks stack, int chunk_div, int future)
{
	t_node		*lst;

	lst = stack.a;
	while (lst && lst->pos <= stack.asize / 2)
	{
		if (lst->num <= chunk_div && future)
			future--;
		else if (lst->num <= chunk_div && !future)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_node	*hold_second(t_stacks stack, int chunk_div, int future)
{
	t_node		*lst;

	lst = stack.a;
	lst = ft_lstlast(lst);
	while (lst && lst->pos > stack.asize / 2)
	{
		if (lst->num <= chunk_div && future)
			future--;
		else if (lst->num <= chunk_div)
			return (lst);
		lst = lst->prev;
	}
	return (NULL);
}
