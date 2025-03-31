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

t_node	*get_smallest(t_node *lst)
{
	t_node *small;
	set_big_small(lst, 0, &small);
	return (small);
}

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
