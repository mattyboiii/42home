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

void	push_prep_rot(t_node **a, t_node **b, t_node *hold, int stack_size)
{
	int		new_size;
	t_node	*hold_a;

	hold_a = hold_first(*a, (*a)->div, 0);
	new_size = stack_size;
	while (new_size == stack_size)
	{
		if ((*a)->num > (*a)->div && if_push(a, b, hold_a) == 0)
			rr(a, b);
		else if ((*a)->num <= (*a)->div && if_push(a, b, *a) == 1)
			pb(a, b, 1);
		else if ((*a)->next->num == hold->num && if_push (a, b, *a) == 0)
			r(b, 1);
		else if ((*a)->num <= (*a)->div && if_push(a, b, *a) == 0)
		{
			s(a, 1);
			rr(a, b);
		}
		else
			r(a, 1);
		new_size = ft_lstlast(*a)->pos + 1;
	}
}
// change this to take in two variables, hold and hold future. if top number is <
// chunk_div try if push on it. If it passes. push it. If it fails. hold its spot
// with swap. either way. I am never using only rb or rrb
void	push_prep_rev(t_node **a, t_node **b, t_node *hold, int	stack_size)
{
	int		new_size;
	t_node	*last;
	t_node	*hold_a;

	hold_a = hold_second(*a, (*a)->div, 0);
	new_size = stack_size;
	while (new_size == stack_size)
	{
		last = ft_lstlast(*a);
		if ((*a)->num > (*a)->div && if_push(a, b, hold_a) == 0)
			rrr(a, b);
		if ((*a)->num <= (*a)->div && if_push(a, b, *a) == 1)
			pb(a, b, 1);
		else if (last->num == hold->num && if_push (a, b, *a) == 0)
			rrs(b, 1);
		else if ((*a)->num <= (*a)->div && if_push(a, b, *a) == 0)
		{
			rrr(a, b);
			s(a, 1);
		}
		else
			rrs(a, 1);
		new_size = ft_lstlast(*a)->pos + 1;
	}
}
