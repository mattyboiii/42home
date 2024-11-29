/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 03:50:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-25 03:50:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rot_checks_swap(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num <= stk->a->div && stk->a->next->num <= stk->a->div
			&& if_push(*stk, stk->a->next) == 1)
		s(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 0)
		rr(stk, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else if (stk->a->num <= stk->a->div && stk->a->next->num <= stk->a->div)
		r(&stk->a, out);
	else if (stk->a->num <= stk->a->div)
		s(&stk->a, out);
	return (1);
}

int	rev_checks_swap(t_stacks *stk, t_node *hold, int out)
{
	t_node		*last;

	last = ft_lstlast(stk->a);
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (last->num <= stk->a->div && if_push(*stk, last) == 1)
		rrs(&stk->a, out);
	else if (stk->a->num > stk->a->div && if_push(*stk, stk->a) == 0)
		rrr(stk, out);
	else if (stk->a->num <= stk->a->div)
		s(&stk->a, out);
	return (1);
}


