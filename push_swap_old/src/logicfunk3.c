/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:57 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:30:21 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_prep(t_stacks stack, t_node *hold, int chunk)
{
	int		rb;
	int		rrb;

	if (stack.bsize < 2)
		return (0);
	rb = order_rot_push(stack, &stack.b, hold, chunk);
	rrb = order_rev_push(stack, &stack.b, hold, chunk);
	if (rb <= rrb)
		return (rb);
	else if (rb > rrb)
		return (rrb *= -1);
	return (0);
}

/**
 * @brief order_rev_push simiulates pushing the hold node into stack b. It will
 * then check if the number is in the correct order. It will continue to do
 * this while it is not in the right order, counting how many times it reverse
 * rotates the stack. Returning this value.
 *
 * @return int, amount of times stack will reverse untill hold is pushed
 * in the right order.
 */
int	order_rev_push(t_stacks stack, t_node **b, t_node *hold, int chunk)
{
	int			rev;
	t_stacks	stack_temp;

	if (ft_lstsize(*b) < 2)
		return (0);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(*b);
	rev = 0;
	stack_temp.b->chunk = chunk;
	pb(&stack_temp, 0);
	while (order_check(&stack_temp.b) == 0 && rev <= stack.div)
	{
		if (stack_temp.b->num == hold->num)
			pa(&stack_temp, 0);
		rrs(&stack_temp.b, 0);
		rev++;
		pb(&stack_temp, 0);
	}
	ft_lstclear(&stack_temp.a);
	ft_lstclear(&stack_temp.b);
	return (rev);
}

/**
 * @brief works the same as order_rev_push but with rotate
 *
 * @return int, amount of times stack will rotate untill hold is pushed
 * in the right order.
 */
int	order_rot_push(t_stacks stack, t_node **b, t_node *hold, int chunk)
{
	int			rot;
	t_stacks	stack_temp;

	if (ft_lstsize(*b) < 2)
		return (0);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(*b);
	rot = 0;
	stack_temp.b->chunk = chunk;
	pb(&stack_temp, 0);
	while (order_check(&stack_temp.b) == 0 && rot <= stack.div)
	{
		if (stack_temp.b->num == hold->num)
			pa(&stack_temp, 0);
		r(&stack_temp.b, 0);
		rot++;
		pb(&stack_temp, 0);
	}
	ft_lstclear(&stack_temp.a);
	ft_lstclear(&stack_temp.b);
	return (rot);
}

/**
 * @brief order_check checs the order of the list. The funciton first
 * turns the list into a circle, so that it will loop forever unless a
 * condition is met. It will start at the number following the biggest.
 * if the number is smaller, it will keep going, if not. it will return
 * 0
 *
 * if it loops completely, by hitting the biggest number again, it will
 * exit, cut the circle then return 1
 *
 * @return returns 1 or 0. 1 meaning it is successfully in order
 */
int	order_check(t_node **lst)
{
	int		cut;
	t_node	*big;
	t_node	*compare;

	if (ft_lstsize(*lst) <= 2)
		return (1);
	set_big_small(*lst, &big, 0);
	cut = make_circle(lst);
	compare = big->next;
	while (compare != big)
	{
		if (compare->num > compare->prev->num)
		{
			cut_circle(lst, cut);
			return (0);
		}
		compare = compare->next;
	}
	cut_circle(lst, cut);
	return (1);
}

void	check_rotate_value(t_stacks stack, t_hold *hold)
{
	int		ops_top;
	int		ops_bot;

	ops_top = force_rotate_check(stack, hold->gold, 1);
	ops_bot = force_rotate_check(stack, hold->gold, -1);
	if (ops_top <= ops_bot)
		hold->rotate = 1;
	else
		hold->rotate = -1;
}
