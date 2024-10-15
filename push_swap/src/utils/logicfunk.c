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

void	big_small_set(t_node *lst, t_node *big, t_node *small)
{
	big = lst;
	small = lst;
	while (lst->next)
	{
		lst = lst->next;
		if (lst->num < small->num)
			small = lst;
		else if (lst->num > big->num)
			big = lst;
	}
}

void	big_mid(t_node *lst, t_node *big, t_node *small)
{
		if (small->pos == 0)
		{
			s(lst, 1);
			r(lst, 1);
		}
		else
			rra(lst, 1);
}
void	sort3(t_node *a)
{
	t_node		*small;
	t_node		*big;

	big_small_set(a, big, small);
	if (big->pos < 2)
		big_mid(a, big, small);
	else if (small->pos == 1)
	{
		if (big->pos == 2)
			s(a, 1);
		else
			r(a, 1);
	}
	else
	{
		s(a, 1);
		rra(a, 1);
	}
}
