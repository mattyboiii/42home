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
