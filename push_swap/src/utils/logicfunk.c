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

/* somthing to do with holding onto the clsoe numbers using swap when a number
is already at the top, if a number at the top of a is < chunk_div, then I dont
need to push the number back to the node, I can just swap and rotate to try and
get the next hold number closer up, while also finding the right position.*/

/* i am not using rotate prep, even though its important I shuold be considering
the rotations for B as well as rotations for a */

int	rotate_prep(t_stacks stack, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;

	if (hold->pos < stack.asize / 2 && stack.bsize <= 2)
		return (0);
	else if (hold->pos >= stack.asize / 2 && stack.bsize <= 2)
		return (-1);
	rb = order_rot_push(&stack.b, hold, chunk);
	rrb = order_rev_push(&stack.b, hold, chunk);
	if (rb <= rrb)
		return (rb);
	else if (rb > rrb)
		return (rrb *= -1);
}

int	closest_hold(t_stacks stack, t_node **hold_a, t_node **hold_b, int future)
{
	*hold_a = hold_first(stack.a, stack.a->div, future);
	*hold_b = hold_second(stack.a, stack.a->div, future);
}

// find out if I am rot or rev to get the number in order. because I will
// continually just swap the top numbers of both stacks untill one fits. Then
// move onto the next.
t_node	 *least_ops(t_stacks stack, t_node *hold_a, t_node *hold_b, t_node *g_hold)
{
	int		ops_top;
	int		ops_bot;

	// for now only try the lower rotate_prep
	// get the least amount of moves compared to the position
	if (!hold_a && hold_b)
		return (hold_b);
	if (hold_a && !hold_b)
		return (hold_a);
	ops_top = rotate_prep(stack, hold_a, stack.a->chunk);
	ops_bot = rotate_prep(stack, hold_b, stack.a->chunk);
	if (hold_a->pos > stack.bsize - hold_b->pos && stack.bsize < 2)
		return (hold_b);
	if (ops_top < 0 && ops_bot >= 0)
		return (NULL);
	else if (ops_top <= posnum(ops_bot))
		return (hold_a);
	else if (ops_top > posnum(ops_bot))
		return (hold_b);

}
/* have two functions that loop and try all numbers. and return the cheapest
move with desired algorythm. Then compare them below. */
//int		try_swap(t_stacks stack,

void	ra_or_rra(t_stacks *stack, int chunk)
{
	int			rotate;
	int			new_rotate;
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
			g_hold = least_ops(*stack, hold_a, hold_b, g_hold);
		else
			t_hold = least_ops(*stack, hold_a, hold_b, g_hold);
		if (rotate == 100)
		{
			rotate = push_prep_rotate(*stack, g_hold);
		}
		if (t_hold)
		{
			new_rotate = push_prep_rotate(*stack, t_hold);
		}
		if (t_hold && new_rotate < rotate)
		{
			p_hold = g_hold;
			p_rotate = rotate;
			g_hold = t_hold;
			rotate = new_rotate;

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
/*
void	ra_or_rra(t_stacks stack, int chunk)
{
	t_node		*last;
	t_node		*hold_a;
	t_node		*hold_b;
	static t_node *s_chunk;

	if (!s_chunk || s_chunk->chunk != chunk)
		s_chunk = sorted_chunk(stack->a, s_chunk, chunk, stack.a->div);
	hold_a = hold_first(stack->a, stack.a->div, 0);
	hold_b = hold_second(stack->a, stack.a->div, 0);
	last = ft_lstlast(stack->a);
	if (hold_a && (!hold_b || hold_a->pos <= last->pos - hold_b->pos))
		push_prep(&stack, hold_a, s_chunk);
	else if (hold_b && (!hold_a || hold_a->pos > last->pos - hold_b->pos))
		push_prep(&stack, hold_stack->b, s_chunk);
}
*/

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

	print_lstnums(stack->a, stack->b);
	chunk = 1;
	chunk_div = get_chunk_number(stack->a);
	chunk_add = chunk_div;
	update_chunk_div(stack->a, chunk_div, chunk);
	while (chunk_size(stack->a, chunk))
	{
		while (check_lg_sm(stack->a, chunk_div + 1, chunk, 0) == 1)
		{
			ra_or_rra(stack, chunk);
			ft_putendl_fd("------------Current Stage------------", 1);
			print_lstnums(stack->a, stack->b);
		}
		if (stack->a)
			chunk++;
		chunk_div = chunk_div + chunk_add;
		update_chunk_div(stack->a, chunk_div, chunk);
	}
	sort_to_a(stack, chunk);
}
