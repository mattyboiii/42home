/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-04 07:33:29 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_small_set(t_node **lst, t_node **big, t_node **small)
{
	t_node	*head;

	head = *lst;
	*big = *lst;
	*small = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		if ((*lst)->num < (*small)->num)
			*small = *lst;
		else if ((*lst)->num > (*big)->num)
			*big = *lst;
	}
	*lst = head;
}

void	sort3(t_node **a)
{
	t_node		*small;
	t_node		*big;

	big_small_set(a, &big, &small);
	if (small->pos == 1 && big->pos == 2)
		s(a, 1);
	else if (small->pos == 1 && big->pos == 0)
		r(a, 1);
	else if (small->pos == 2 && big->pos == 1)
		rrs(a, 1);
	else if (small->pos == 0 && big->pos == 1)
	{
		s(a, 1);
		r(a, 1);
	}
	else
	{
		s(a, 1);
		rrs(a, 1);
	}
}
