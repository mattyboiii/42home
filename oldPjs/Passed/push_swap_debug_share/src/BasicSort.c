/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:32:04 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief loops through the stack to return the node with the smallest
 * value.
 *
 * @return node with smallest number.
 */
t_node	*get_smallest(t_node *lst)
{
	t_node		*small;

	set_big_small(lst, 0, &small);
	return (small);
}

/**
 * @brief Can use this function like set_big_small(lst, 0, &small) to only
 * set a small value & vice versa.
 * Loops through the stack and sets the "big" & "small" values
 * to the node with the biggest number, and smallest, node with the smallest
 * number.
 */
void	set_big_small(t_node *lst, t_node **big, t_node **small)
{
	t_node	*head;

	head = lst;
	if (small)
		*small = lst;
	if (big)
		*big = lst;
	while (small && lst->next)
	{
		lst = lst->next;
		if (lst->num < (*small)->num)
			*small = lst;
	}
	lst = head;
	while (big && lst->next)
	{
		lst = lst->next;
		if (lst->num > (*big)->num)
			*big = lst;
	}
}

/**
 * @brief sorts a stack with 3 numbers into ascending order using the allowed
 * commands.
 */
void	sort3(t_node **lst)
{
	t_node		*small;
	t_node		*big;

	if (sorted_asc(*lst, *lst) == 1)
		return ;
	set_big_small(*lst, &big, &small);
	if (small->pos == 1 && big->pos == 2)
		s(lst, 1);
	else if (small->pos == 1 && big->pos == 0)
		r(lst, 1);
	else if (small->pos == 2 && big->pos == 1)
		rrs(lst, 1);
	else if (small->pos == 0 && big->pos == 1)
	{
		s(lst, 1);
		r(lst, 1);
	}
	else
	{
		s(lst, 1);
		rrs(lst, 1);
	}
}
