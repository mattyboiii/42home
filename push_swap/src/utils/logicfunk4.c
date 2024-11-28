/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 21:23:15 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-03 21:23:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// comp = compare
int	order_check(t_node **lst, int chunk)
{
	int		cut;
	t_node	*big;
	t_node	*comp;

	if (ft_lstsize(*lst) <= 2)
		return (1);
	set_big_small(*lst, &big, 0);
	cut = make_circle(lst);
	comp = big->next;
	while (comp != big)
	{

		if (comp->num > comp->prev->num)
		{
			cut_circle(lst, cut);
			return (0);
		}
		comp = comp->next;
	}
	cut_circle(lst, cut);
	return (1);
}

// for now, i am just going to check if the number is within 2 next or prev
// rc = rotate count.

int	order_rot_push(t_node **b, t_node *hold, int chunk)
{
	int			rot;
	t_stacks	stack_temp;

	if (chunk <= 1 && chunk_size(*b, chunk) < 2)
		return (0);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(*b);
	rot = 0;
	stack_temp.b->chunk = chunk;
	pb(&stack_temp, 0);
	while (order_check(&stack_temp.b, chunk) == 0 && rot <= hold->div)
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

int	order_rev_push(t_node **b, t_node *hold, int chunk)
{
	int			rev;
	t_stacks	stack_temp;

	if (chunk <= 1 && chunk_size(*b, chunk) < 2)
		return (0);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(*b);
	rev = 0;
	stack_temp.b->chunk = chunk;
	pb(&stack_temp, 0);
	while (order_check(&stack_temp.b, chunk) == 0 && rev <= hold->div)
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
