/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 03:50:43 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-05 03:50:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	if_push(t_stacks stack, t_node *hold)
{
	t_stacks	stack_temp;

	if (stack.b == NULL || stack.b->next == NULL)
		return (1);
	stack_temp.a = copy_node(hold);
	stack_temp.b = copy_lst(stack.b);
	pb(&stack_temp, 0);

	if (order_check(&stack_temp.b) == 1)
	{
		ft_lstclear(&stack_temp.a);
		ft_lstclear(&stack_temp.b);
		return (1);
	}
	else
	{
		ft_lstclear(&stack_temp.a);
		ft_lstclear(&stack_temp.b);
		return (0);
	}
}

void	rot_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		r(lst, print);
		n--;
	}
}

void	rev_machine(t_node **lst, int n, int print)
{
	while (n > 0)
	{
		rrs(lst, print);
		n--;
	}
}
