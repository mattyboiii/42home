/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 22:47:49 by mtripodi          #+#    #+#             */
/*   Updated: 2025-03-31 22:47:49 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief force rot push is responsible for checking if rr can be used instead
 * of rotating stacks individually. It uses the mid_h variable which tells it
 * the direction it can go. Used in the situation stacks can rotate in the
 * same diretion.
 */
void	force_rot_push(t_stacks *stack, t_node *push)
{
	int		stacksize;

	stacksize = stack->bsize;
	while (stack->bsize == stacksize)
	{
		if (stack->b != push && stack->a != push->target)
			rr(stack, 1);
		else if (stack->b != push && stack->a == push->target)
			r(&(stack->b), 1);
		else if (stack->b == push && stack->a != push->target)
			r(&(stack->a), 1);
		else if (stack->b == push && stack->a == push->target)
			pa(stack, 1);
		set_mid_h(stack);
	}
}

/**
 * @brief force rev push is responsible for checking if rrr can be used instead
 * of rotating stacks individually. It uses the mid_h variable which tells it
 * the direction it can go. Used in the situation stacks can rotate in the
 * same diretion
 */
void	force_rev_push(t_stacks *stack, t_node *push)
{
	int		stacksize;

	stacksize = stack->bsize;
	while (stack->bsize == stacksize)
	{
		if (stack->b != push && stack->a != push->target)
			rrr(stack, 1);
		else if (stack->b != push && stack->a == push->target)
			rrs(&(stack->b), 1);
		else if (stack->b == push && stack->a != push->target)
			rrs(&(stack->a), 1);
		else if (stack->b == push && stack->a == push->target)
			pa(stack, 1);
		set_mid_h(stack);
	}
}

/**
 * @brief man push simply uses push-pos and push->target->pos to dictate
 * how and which direction the stack wants to move. Man push always rotates
 * stacks individually. It is used in the situation that its quicker to
 * rotate stacks in opposite directions.
 */
void	man_push(t_stacks *stack, t_node *push)
{
	if (stack->a != push->target && push->target->mid_h == true)
		rot_machine(&(stack->a), push->target->pos, 1);
	else if (stack->a != push->target && push->target->mid_h == false)
		rev_machine(&(stack->a), stack->asize - push->target->pos, 1);
	set_mid_h(stack);
	if (stack->b != push && push->mid_h == true)
		rot_machine(&(stack->b), push->pos, 1);
	else if (stack->b != push->target && push->mid_h == false)
		rev_machine(&(stack->b), stack->bsize - push->pos, 1);
	pa(stack, 1);
	set_mid_h(stack);
}

/**
 * @brief push cheapest is responsible for deciding how it will get
 * the cheap node to the opposing stack. It does this by using
 * mid_h variable in cheap and cheap->target. It prioritises rr, next
 * rrr. If it can not rotate stacks the same way, it will run man_push.
 *
 * it works this way for maxium efficiency, as if using rr or rr is
 * valid, it will almost certainly use less actions.
 */
void	push_cheapest(t_stacks *stack, t_node *cheap)
{
	if (cheap->mid_h == true && cheap->target->mid_h == true)
		force_rot_push(stack, cheap);
	else if (cheap->mid_h == false && cheap->target->mid_h == false)
		force_rev_push(stack, cheap);
	else
		man_push(stack, cheap);
}

/**
 * @brief smallest on top, simply finds the smallest number in the
 * stack, and rotates the stack so that its on top. It does this
 * to finalise sorting the stacks in ascending order.
 */
void	smallest_on_top(t_stacks *stack)
{
	t_node		*small;

	set_big_small(stack->a, 0, &small);
	while (stack->a != small)
	{
		if (small->mid_h == true)
			rot_machine(&(stack->a), small->pos, 1);
		else
			rev_machine(&(stack->a), stack->asize - small->pos, 1);
		set_mid_h(stack);
	}
}
