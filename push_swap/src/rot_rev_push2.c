/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev_push2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 22:49:55 by mtripodi          #+#    #+#             */
/*   Updated: 2025-03-31 22:49:55 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief calculates the push price in the event that "rr" or "rrr" will be
 * used. This function is only called after *b and *b->target (mid_h) values
 * are equal. This function is used, so that the algorithm takes into account
 * "rr" and "rrr" without it. It would only calculate push_price as if
 * only one stack could be roated at a time.
 */
void	set_rr_rrr_push_price(t_stacks stack, t_node *b)
{
		int		bpos;
		int		tpos;

		if (b->mid_h == true)
		{
			bpos = b->pos;
			tpos = b->target->pos;
			if (bpos >= tpos)
				b->push_price = tpos + (bpos - tpos);
			else
				b->push_price = bpos + (tpos - bpos);
		}
		else
		{
			bpos = stack.bsize - b->pos;
			tpos = stack.asize - b->target->pos;
			if (bpos >= tpos)
				b->push_price = tpos + (bpos - tpos);
			else
				b->push_price = bpos + (tpos - bpos);
		}
}

void	rot_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		r(lst, print);
		n--;
	}
}

void	rev_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		rrs(lst, print);
		n--;
	}
}
