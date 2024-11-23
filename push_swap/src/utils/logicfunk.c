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

	if (g_hold == NULL && hold_a)
		return (hold_a);
	else if (g_hold == NULL && hold_b)
		return (hold_b);
	// for now only try the lower rotate_prep
	// get the least amount of moves compared to the position
	ops_top = rotate_prep(stack, hold_a, stack.a->chunk);
	ops_bot = rotate_prep(stack, hold_b, stack.a->chunk);
	if (ops_top < 0 && ops_bot >= 0)
		return (NULL);
	else if (ops_top < posnum(ops_bot))
		return (hold_a);
	else if (posnum(ops_bot) < ops_top)
		return (hold_a);

}

void	ra_or_rra(t_stacks *stack, int chunk)
{
	int			rotate;
	int			i;
	t_node		*hold_a;
	t_node		*hold_b;
	t_node		*g_hold;


	i = 0;
	while (i < 3)
	{
		closest_hold(*stack, &hold_a, &hold_b, i);
		g_hold = least_ops(*stack, hold_a, hold_b, g_hold);
	}
	push_prep(stack, g_hold, rotate, 1);
	print_lstnums(stack->a, stack->b);
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
	int		size;
	t_node	*big;

	while (stack->b)
	{
		size = ft_lstlast(stack->b)->pos + 1;
		set_big_small(stack->b, &big, 0);
		if (big->pos < size / 2)
			rot_machine(&stack->b, big->pos, 1);
		else if (big->pos > size / 2)
			rev_machine(&stack->b, size - big->pos, 1);
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
			print_lstnums(stack->a, stack->b);
		}
		if (stack->a)
			chunk++;
		chunk_div = chunk_div + chunk_add;
		update_chunk_div(stack->a, chunk_div, chunk);
	}
	sort_to_a(stack, chunk);
}
