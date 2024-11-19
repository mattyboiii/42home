/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 05:39:20 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-13 05:39:20 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	make_chunk_circle(t_node **lst, t_node **old_next, int chunk)
{
	t_node	*last;

	last = lstlast_chunk(*lst, chunk);
	*old_next = last->next;
	(*lst)->prev = last;
	last->next = *lst;
	return (last->num);
}

void	cut_circle(t_node **lst, t_node *old_next, int cut)
{
	t_node *head;

	head = *lst;
	if (*lst == NULL)
		return ;
	if ((*lst)->prev->num == cut)
		(*lst)->prev = NULL;
	while (*lst)
	{
		if ((*lst)->num == cut)
		{
			(*lst)->next = old_next;
			*lst = head;
			return ;
		}
		*lst = (*lst)->next;
	}
}

void	push_prep_rot(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	int		push;

	push = 0;
	while (prep_b > 0 && push == 0)
	{
		if (*a != hold)
			rr(a, b);
		else if (*a == hold && if_push(a, b, hold) == 1)
		{
			push++;
			pb(a, b, 1);
		}
		else if (*a == hold && if_push(a, b, hold) == 0)
		{
			s(a, 1);
			rr(a, b);
		}
		prep_b--;
	}
	while (*a != hold)
		r(a, 1);
}

// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
void	push_prep_rev(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	int		push;

	push = 0;
	while (prep_b < 0 && push == 0)
	{
		if (*a != hold)
			rrs(a, b);
		else if (*a == hold && if_push(a, b, hold) == 1)
		{
			push++;
			pb(a, b, 1);
		}
		else if (*a == hold && if_push(a, b, hold) == 0)
		{
			s(a, 1);
			rrs(a, b);
		}
		prep_b++;
	}
	while (*a != hold)
		rr(a, 1);
}
