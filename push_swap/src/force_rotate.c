/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:02:45 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 15:27:53 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_ops_data(t_stacks stack, t_hold *hold)
{
		hold->ops_fh = 100;
		hold->ops_sh = 100;
		if (stack.asize >= 20)
		{
			if (hold->fh)
				hold->ops_fh = force_rotate_check(stack, hold->fh, 1);
			if (hold->sh)
				hold->ops_sh = force_rotate_check(stack, hold->sh, -1);
		}
		else
		{
			if (hold->fh)
				hold->ops_fh = check_rrr_rr(stack, hold->fh, hold);
			if (hold->sh)
				hold->ops_sh = check_rrr_rr(stack, hold->sh, hold);
		}
}

void	set_compare(t_stacks stack, t_hold *hold)
{
	if (!hold->gold)
		return ;
	if (!hold->fh || !hold->sh)
	{
		if ((hold->fh && !hold->sh) || stack.asize <= 1)
			hold->compare = hold->ops_fh;
		if (!hold->fh && hold->sh)
			hold->compare = hold->ops_sh;
	}
	else
	{
		if (hold->ops_fh <= posnum(hold->ops_sh))
			hold->compare = hold->ops_fh;
		else
			hold->compare = hold->ops_sh;
	}
}

void check_set_temp(t_stacks stack, t_hold *hold)
{
	if (!hold->fh || !hold->sh)
	{
		if ((hold->fh && !hold->sh) || stack.asize <= 1)
			hold->temp = hold->fh;
		if (!hold->fh && hold->sh)
			hold->temp = hold->sh;
	}
	else
	{
		if (hold->ops_fh <= posnum(hold->ops_sh))
			hold->temp = hold->fh;
		else
			hold->temp = hold->sh;
	}
}

void check_temp_gold(t_stacks stack, t_hold *hold)
{
	if (!hold->gold && (!hold->fh || !hold->sh))
	{
		if ((hold->fh && !hold->sh) || stack.asize <= 1)
			hold->gold = hold->fh;
		if (!hold->fh && hold->sh)
			hold->gold = hold->sh;
	}
	else
	{
		if (!hold->gold)
		{
			if (hold->ops_fh <= posnum(hold->ops_sh))
				hold->gold = hold->fh;
			else
				hold->gold = hold->sh;
		}
		else
			check_set_temp(stack, hold);
	}
}
/**
 * @brief force loop, is an efficient way to try the force_rotate_check on
 * different potential hold numbers. Somtimes, Its more efficient to use logic
 * on a number that is further away from the top of the stack. Which is why the
 * loop checks itself against hold->iterations. Iterations is set to 10 by
 * defualt. Loop is set to 0.
 *
 * It will check the first available 10 numbers. Then set hold->gold as the
 * number which has the fewest actions to push to b.
 *
 * @return it returns the number of actions the force_rotate function would take
 * to correclty push hold->gold into the b stack.
 */
int	force_loop(t_stacks stack, t_hold *hold, t_node **gold_hold, int loop)
{
	while (loop < hold->iterations)
	{
		closest_hold(stack, hold, loop);
		if (!hold->fh && !hold->sh)
			break ;
		get_ops_data(stack, hold);
		check_temp_gold(stack, hold);
		set_compare(stack, hold);
		if (hold->temp && posnum(hold->compare) < posnum(hold->ops))
		{
			hold->gold = hold->temp;
			hold->ops = hold->compare;
		}
		if (hold->gold && stack.bsize < 2)
			break ;
		if (hold->ops == 0 || hold->ops == 100)
			hold->ops = hold->compare;
		loop++;
	}
	*gold_hold = hold->gold;
	return (hold->ops);
}

/* force_rotate_check - assymilates using the force logic but with copied
stacks, using the hold which is being tested. None of the changes made will be
applied yet the actions will simply be counted and returned for comparison later.
*/
int	force_rotate_check(t_stacks stack, t_node *hold, int rotate)
{
	int			old_size;
	int			operations;
	t_stacks	stk;

	stk = stacklst_dup(stack);
	operations = 0;
	old_size = stk.asize;
	if (rotate >= 0)
	{
		while (old_size == stk.asize && operations <= 20)
			operations += rot_checks_rotate(&stk, hold, 0);
	}
	else
	{
		while (old_size == stk.asize && operations <= 20)
			operations += rev_checks_rotate(&stk, hold, 0);
	}
	stacklst_del(&stk);
	if (rotate < 0)
		operations *= -1;
	return (operations);
}

/**
 * @brief force_rotate is the functoin that uses the force_loop to see
 * what the lowest amount of actions it can get. It then checks the direction
 * it needs to run, and applies it to the number. Making it a negative or
 * positive numebr.
 *
 * @return returns the lowest amount of actions the logic has discovered. In
 * a negative or positive number.
 */
int	force_rotate(t_stacks stack, t_node **fr_hold, int loop, int skip)
{
	int			rotate;
	t_hold		hold;

	rotate = 0;
	set_holds(&hold, *fr_hold, loop);
	rotate = force_loop(stack, &hold, fr_hold, skip);
	if (!hold.rotate)
		return (rotate);
	else
		return (rotate * hold.rotate);
}

/* rotate_run - is the same as force_rotate_check, but it uses the real stacks.
this is because all calculations have been done and the current hold will yeild
the leat amount of operations
*/
int	rotate_run(t_stacks *stack, t_node *hold, int rotate)
{
	int		old_size;
	int		operations;

	operations = 0;
	old_size = stack->asize;
	if (rotate >= 0)
	{
		while (old_size == stack->asize)
			operations += rot_checks_rotate(stack, hold, 1);
	}
	else
	{
		while (old_size == stack->asize)
			operations += rev_checks_rotate(stack, hold, 1);
	}
	return (operations);
}

/* ops_force is responsible for seeing how many rotations it takes to get
b ready to receive the number in hold_a/b. It uses rr or rrr depending on the
nums positon. It will return the node who has less rotations, or hold_a if
they are equal. this supports my force_rotate logic because I want to force
both stack A and B to move together depending on the number which gives me the
least amount of operations
*/
t_node	*ops_force(t_stacks stack, t_hold *hold, t_node *hold_a,
			t_node *hold_b)
{
	int		ops_top;
	int		ops_bot;

	if ((hold_a && !hold_b) || stack.asize <= 1)
		return (hold_a);
	if (!hold_a && hold_b)
		return (hold_b);
	ops_top = rotate_prep(stack, hold_a, stack.a->chunk);
	ops_bot = rotate_prep(stack, hold_b, stack.a->chunk);
	if (ops_top >= 0 && hold_a->pos < (stack.asize - hold_b->pos))
	{
		hold->rotate = 1;
		return (hold_a);
	}
	if (ops_bot <= 0 && hold_a->pos > (stack.asize - hold_b->pos))
	{
		hold->rotate = -1;
		return (hold_b);
	}
	if (!hold->rotate)
		hold->rotate = 1;
	return (hold_a);
}
