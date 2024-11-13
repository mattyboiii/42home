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

void	push_prep_rr(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	while (prep_b > 0)
	{
		if (*a != hold)
			rr(a, b);
		else
			r(b, 1);
		prep_b--;
	}
	while (*a != hold)
		r(a, 1);

}

void	push_prep_rrr(t_node **a, t_node **b, t_node *hold, int prep_b)
{
	while (prep_b > 0)
	{
		if (*a != hold)
			rrr(a, b);
		else
			rrs(b, 1);
		prep_b--;
	}
	while (*a != hold)
		rrs(a, 1);

}
