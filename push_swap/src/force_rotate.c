/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-30 00:02:45 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-30 00:02:45 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	force_loop(t_stacks stack, t_hold *hold, t_node **gold_hold, int loop)
{
	if (stack.bsize >= 666666)
		ft_printf("");
	while (loop < hold->iterations)
	{
		closest_hold(stack, &hold->fh, &hold->sh, loop);
		if (!hold->fh && !hold->sh)
			break ;
		if (!hold->gold)
			hold->gold = ops_force(stack, hold, hold->fh, hold->sh);
		else
			hold->temp = ops_force(stack, hold, hold->fh, hold->sh);
		if (hold->ops == 100)
			hold->ops = force_rotate_check(stack, hold->gold, hold->rotate);
		if (hold->temp)
			hold->compare = force_rotate_check(stack, hold->temp, hold->rotate);
		if (hold->temp && hold->compare < hold->ops)
		{
			hold->gold = hold->temp;
			hold->ops = hold->compare;
		}
		if (hold->gold && stack.bsize < 2)
			break ;
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
		while (old_size == stk.asize)
			operations += rot_checks_rotate(&stk, hold, 0);
	}
	else
	{
		while (old_size == stk.asize)
			operations += rev_checks_rotate(&stk, hold, 0);
	}
	stacklst_del(&stk);
	return (operations);
}


int	force_rotate(t_stacks stack, t_node **fr_hold, int loop, int skip)
{
	int			rotate;
	t_hold		hold;

	rotate = 0;
	set_holds(&hold, *fr_hold, loop);
	rotate = force_loop(stack, &hold, fr_hold, skip);
	if (stack.bsize >= 9999999999)
		ft_printf("");
	if (rotate == 0)
		rotate = 1;
	else
	{
		if ((*fr_hold)->pos > stack.asize / 2)
			hold.rotate = -1;
		else
			hold.rotate = 1;
	}
	if (hold.rotate < 0)
		rotate *= -1;
	return (rotate);
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
	if (stack->bsize >= 9999999999)
		print_stacks(*stack);
	if (rotate >= 0)
	{
		while (old_size == stack->asize)
		{
			operations += rot_checks_rotate(stack, hold, 1);
		}
	}
	else
	{
		while (old_size == stack->asize)
		{
			operations += rev_checks_rotate(stack, hold, 1);
		}
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

	if (hold_a && !hold_b || stack.asize <= 1)
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
