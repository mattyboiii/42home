/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-04 07:33:29 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotate prep works by counting how many times stack B needs to be rot or rev
to receive the number in hold, so that it will be in order.
*/
int	rotate_prep(t_stacks stack, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;

	if (hold->pos < stack.asize / 2 && stack.bsize < 2)
		return (0);
	else if (hold->pos >= stack.asize / 2 && stack.bsize < 2)
		return (0);
	if (chunk > 1 && hold->num == 40)
		ft_printf("Here");
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

/* least ops is responsible for seeing how many rotations it takes to get
b ready to receive the number in hold_a/b. It uses rr or rrr depending on the
nums positon. It will return the node who has less rotations, or hold_a if
they are equal. this supports my force_rotate logic because I want to force
both stack A and B to move together depending on the number which gives me the
least amount of operations
*/
t_node	 *least_ops_force(t_stacks stack, t_node *hold_a, t_node *hold_b)
{
	int		ops_top;
	int		ops_bot;
	int		rr;
	int		rrr;

	if (!hold_a && hold_b)
		return (hold_b);
	if (hold_a && !hold_b)
		return (hold_a);
	ops_top = rotate_prep(stack, hold_a, stack.a->chunk);
	ops_bot = rotate_prep(stack, hold_b, stack.a->chunk);
	if (hold_a->pos > stack.bsize - hold_b->pos && stack.bsize < 2)
		return (hold_b);
	rr = ops_top - hold_a->pos;
	rrr = posnum(ops_bot) - (stack.bsize - hold_b->pos);
	if (ops_top < 0 && ops_bot > 0 && hold_a->pos < stack.asize - hold_b->pos)
		return (hold_a);
	if (ops_top < 0 && ops_bot > 0 && hold_a->pos > stack.asize - hold_b->pos)
		return (hold_b);
	else if (rr < rrr)
		return (hold_a);
	else if (rrr < rr)
		return (hold_b);
}
/* have two functions that loop and try all numbers. and return the cheapest
move with desired algorythm. Then compare them below. */
//int		try_swap(t_stacks stack,

/*
void	ra_or_rra(t_stacks *stack, int chunk)
{
	int			rotate;
	int			compare;
	int			p_rotate;
	static int	rt;
	static int  prt;
	int			i;
	int			p_pos;
	int			pos;
	t_node		*hold_a;
	t_node		*hold_b;
	t_node		*t_hold;
	t_node		*g_hold;
	t_node		*p_hold;


	rotate = 100;
	if (rotate == 100)
		prt = 0;
	g_hold = NULL;
	p_hold = NULL;
	t_hold = NULL;
	i = 0;
	while (i < 3)
	{
		closest_hold(*stack, &hold_a, &hold_b, i);
		if (!hold_a && !hold_b)
			break ;
		if (!g_hold)
			g_hold = least_ops(*stack, hold_a, hold_b);
		else
			t_hold = least_ops(*stack, hold_a, hold_b);
		if (rotate == 100)
		{
			rotate = push_prep_rotate(*stack, g_hold);
		}
		if (t_hold)
		{
			compare = push_prep_rotate(*stack, t_hold);
		}
		if (t_hold && compare < rotate)
		{
			p_hold = g_hold;
			p_rotate = rotate;
			g_hold = t_hold;
			rotate = compare;

		}
		if (g_hold && stack->bsize < 2)
			break ;
		i++;
	}
	rt += rotate;
	prt += p_rotate;
	pos = g_hold->pos;
	if (pos > stack->asize / 2)
		pos = (stack->asize - pos) * -1;
	if (p_hold)
	{
		p_pos = p_hold->pos;
		if (p_hold->pos > stack->asize / 2)
			p_pos = (stack->asize - p_pos) * -1;
		ft_printf("prt Total: %d\n", prt);
		ft_printf("hold->num: %d\n", p_hold->num);
		ft_printf("hold->pos: %d\n", p_pos);
		ft_printf("Operations: %d\n", p_rotate);
	}
	ft_printf("Rot Total: %d\n", rt);
	ft_printf("hold->num: %d\n", g_hold->num);
	ft_printf("hold->pos: %d\n", pos);
	ft_printf("Operations: %d\n", rotate);
	ft_putendl_fd("------------before_push------------", 1);
	print_lstnums(stack->a, stack->b);
	push_prep(stack, g_hold);
}
*/


void	set_holds(t_hold *hold, t_node *gold_hold, int iterations)
{
	hold->fh = NULL;
	hold->sh = NULL;
	hold->gold = gold_hold;
	hold->temp = NULL;
	hold->iterations = iterations;
	hold->rotate = 100;
	hold->compare = 0;
}

int	force_loop(t_stacks stack, t_hold hold, t_node **gold_hold, int loop)
{
	if (stack.a->chunk > 1)
		ft_printf("here\n");
	while (loop < hold.iterations)
	{
		closest_hold(stack, &hold.fh, &hold.sh, loop);
		if (!hold.fh && !hold.sh)
			break ;
		if (!hold.gold)
			hold.gold = least_ops_force(stack, hold.fh, hold.sh);
		else
			hold.temp = least_ops_force(stack, hold.fh, hold.sh);
		if (hold.rotate == 100)
			hold.rotate = push_prep_rotate(stack, hold.gold);
		if (hold.temp)
			hold.compare = push_prep_rotate(stack, hold.temp);
		if (hold.temp && hold.compare < hold.rotate)
		{
			hold.gold = hold.temp;
			hold.rotate = hold.compare;
		}
		if (hold.gold && stack.bsize < 2)
			break ;
		loop++;
	}
	*gold_hold = hold.gold;
	return (hold.rotate);
}

int	force_rotate(t_stacks stack, t_node **fr_hold, int loop, int skip)
{
	int			rotate;
	t_hold		hold;

	rotate = 0;
	set_holds(&hold, *fr_hold, loop);
	rotate = force_loop(stack, hold, fr_hold, skip);
	return (rotate);
}

int	 least_ops_man(t_stacks stack, t_node *hold_a, t_node *hold_b,
						t_node	**gold_hold)
{
	int		ops_top;
	int		ops_bot;

	ops_top = 1000;
	ops_bot = 1000;
	if (hold_a)
		ops_top = posnum(rotate_prep(stack, hold_a, stack.a->chunk)) + hold_a->pos;
	if (hold_b)
		ops_bot = posnum(rotate_prep(stack, hold_b, stack.a->chunk))
		+ (stack.asize - hold_b->pos);
	if (ops_top <= ops_bot)
	{
		*gold_hold = hold_a;
		return (ops_top + 1);
	}
	else if (ops_top > ops_bot)
	{
		*gold_hold = hold_b;
		return (ops_bot + 1);
	}
}

int	manual_loop(t_stacks stack, t_hold hold, t_node **gold_hold, int loop)
{
	while (loop < hold.iterations)
	{
		closest_hold(stack, &hold.fh, &hold.sh, loop);
		if (!hold.fh && !hold.sh)
			break ;
		if (!hold.gold)
			hold.rotate = least_ops_man(stack, hold.fh, hold.sh, &hold.gold);
		else
			hold.compare = least_ops_man(stack, hold.fh, hold.sh, &hold.temp);
		if (hold.temp && hold.compare < hold.rotate)
		{
			hold.gold = hold.temp;
			hold.rotate = hold.compare;
		}
		if (hold.gold && stack.bsize < 2)
			break ;
		loop++;
	}
	*gold_hold = hold.gold;
	return (hold.rotate);
}

int	manual_rotate(t_stacks stack, t_node **man_hold, int loop, int skip)
{
	int			rotate;
	t_hold		hold;

	rotate = 0;
	set_holds(&hold, NULL, loop);
	rotate = manual_loop(stack, hold, man_hold, skip);
	return (rotate);
}

int	manual_run(t_stacks *stack, t_node *hold)
{
	int		rotate;
	int		operations;

	rotate = 0;
	operations = 0;
	rotate = rotate_prep(*stack, hold, stack->a->chunk);
	if (hold->pos < stack->asize / 2)
		operations = hold->pos + rotate;
	else if (hold->pos > stack->asize / 2)
		operations = (stack->asize - hold->pos) + rotate;
	if (hold->pos < stack->asize / 2)
		rot_machine(&stack->a, hold->pos, 1);
	else if (hold->pos > stack->asize / 2)
		rev_machine(&stack->a, stack->asize - hold->pos, 1);
	if (rotate >= 0)
		rot_machine(&stack->b, rotate, 1);
	else
		rev_machine(&stack->b, posnum(rotate), 1);
	pb(stack, 1);
	return (operations + 1);
}

int	compare_logic(t_stacks *stack, int chunk, int skip)
{
	int			f_rotate;
	int			m_rotate;
	t_node		*fr_hold;
	t_node		*man_hold;

	fr_hold = NULL;
	man_hold = NULL;
	skip = 0;
	f_rotate = 0;
	m_rotate = 0;
	f_rotate = force_rotate(*stack, &fr_hold, 1, skip);
	print_lstnums(stack->a, stack->b);
	m_rotate = manual_rotate(*stack, &man_hold, 1, skip);
	ft_printf("f_rotate: %d\nfr_hold: %d\n\n", f_rotate, fr_hold->num);
	ft_printf("m_rotate: %d\nma_hold: %d\n", m_rotate, man_hold->num);
	ft_putendl_fd("------------before_push------------", 1);
	print_lstnums(stack->a, stack->b);
	if (f_rotate <= m_rotate)
		return (rotate_run(stack, fr_hold));
	else
		return (manual_run(stack, man_hold));
}

void	sort_to_a(t_stacks *stack, int chunk)
{
	t_node	*big;

	while (stack->b)
	{
		set_big_small(stack->b, &big, 0);
		if (big->pos < stack->asize / 2)
			rot_machine(&stack->b, big->pos, 1);
		else if (big->pos > stack->asize / 2)
			rev_machine(&stack->b, stack->asize - big->pos, 1);
		pa(stack, 1);
	}
}


void	sort_to_b(t_stacks *stack)
{
	int		chunk_div;
	int		chunk_add;
	int		chunk;
	int		total;

	total = 0;
	chunk = 1;
	chunk_div = get_chunk_number(stack->a);
	chunk_add = chunk_div;
	update_chunk_div(stack->a, chunk_div, chunk);
	while (chunk_size(stack->a, chunk))
	{
		while (check_lg_sm(stack->a, chunk_div + 1, chunk, 0) == 1)
			total += compare_logic(stack, chunk, 0);
		if (stack->a)
			chunk++;
		chunk_div = chunk_div + chunk_add;
		update_chunk_div(stack->a, chunk_div, chunk);
	}
	sort_to_a(stack, chunk);
}
