/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 03:50:43 by mtripodi          #+#    #+#             */
/*   Updated: 2025/03/07 13:01:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posnum(int num)
{
	if (num < 0)
		return (num *= -1);
	else
		return (num);
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
