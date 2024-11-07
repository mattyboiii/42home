/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 03:50:43 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-05 03:50:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	adv_rot_machin(t_node **lst, int n, int print)
{

}

void	
