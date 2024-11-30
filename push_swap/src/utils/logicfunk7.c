/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 01:47:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-17 01:47:50 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	posnum(int num)
{
	if (num < 0)
		return (num *= -1);
	else
		return (num);
}

/* rotate prep works by counting how many times stack B needs to be rot or rev
to receive the number in hold, so that it will be in order.
*/
int	rotate_prep(t_stacks stack, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;

	if (stack.bsize < 2)
		return (0);
	rb = order_rot_push(&stack.b, hold, chunk);
	rrb = order_rev_push(&stack.b, hold, chunk);
	if (rb <= rrb)
		return (rb);
	else if (rb > rrb)
		return (rrb *= -1);
}

/* closest hold simply applys the node whos number is <= divider, to
hold_a or hold_b, depending on their position. If its in the first half of the
stack, it will go to hold_a, if its in the second half of the stack it will
belong to hold_b. the future, simply allows me to skip over however many
node's which apply to the <= divider logic. In case the number after the closest
allows for less operations when sending it to b/
*/
int	closest_hold(t_stacks stack, t_node **hold_a, t_node **hold_b, int future)
{
	*hold_a = hold_first(stack.a, stack.a->div, future);
	*hold_b = hold_second(stack.a, stack.a->div, future);
}

int	negnum(int num)
{
	if (num > 0)
		return (num *= -1);
	else
		return (num);
}
