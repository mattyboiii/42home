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


/** Added 7.03.2025
 * @brief this function will return 1 if the pos of the hold + 1 is greater
 * than the hold->compare number. Because hold->compare represents the amount
 * of operations it takes to push to b. If the pos is greater, there is no
 * point simulating that hold as it will never be more efficient
 *
 * @return int - we want it to return 1, as this will increase efficiency
 */
int	pos_greater_than_ops(t_hold hold, t_node node)
{
	int	ops;
	int	pos;

	pos = node.pos + 1;
	ops = hold.compare;
	if (ops && ops <= pos)
		return (1);
	return (0);
}

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
