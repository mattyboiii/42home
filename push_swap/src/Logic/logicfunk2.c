/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-29 23:59:11 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-30 00:48:05 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_number(t_node *lst)
{
	int		chunk_step;
	t_node	*big;
	t_node	*small;

	set_big_small(lst, &big, &small);
	if (ft_lstlast(lst)->pos <= 99)
		chunk_step = ((big->num - small->num) / 5);
	if (ft_lstlast(lst)->pos > 99)
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

/* closest hold simply applys the node whos number is <= divider, to
hold_a or hold_b, depending on their position. If its in the first half of the
stack, it will go to hold_a, if its in the second half of the stack it will
belong to hold_b. the future, simply allows me to skip over however many
node's which apply to the <= divider logic. In case the number after the closest
allows for less operations when sending it to b/
*/
int	closest_hold(t_stacks stack, t_node **hold_a, t_node **hold_b, int future)
{
	*hold_a = hold_first(stack, stack.a->div, future);
	*hold_b = hold_second(stack, stack.a->div, future);
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
