/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-30 02:28:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-30 00:48:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	order_rev_push(t_node **b, t_node *hold, int chunk)
{
	int			rev;
	t_stacks	stack_temp;

	if (ft_lstsize(*b) <= 2)
		return (0);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(*b);
	rev = 0;
	stack_temp.b->chunk = chunk;
	pb(&stack_temp, 0);
	while (order_check(&stack_temp.b) == 0 && rev <= hold->div)
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

int	order_rot_push(t_node **b, t_node *hold, int chunk)
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
	while (order_check(&stack_temp.b) == 0 && rot <= hold->div)
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

int	posnum(int num)
{
	if (num < 0)
		return (num *= -1);
	else
		return (num);
}
