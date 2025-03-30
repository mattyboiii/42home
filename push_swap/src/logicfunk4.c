/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:23:15 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:25:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_circle(t_node **lst)
{
	t_node	*last;

	last = ft_lstlast(*lst);
	(*lst)->prev = last;
	last->next = *lst;
	return (last->num);
}

void	cut_circle(t_node **lst, int cut)
{
	t_node	*head;

	head = *lst;
	if (*lst == NULL)
		return ;
	if ((*lst)->prev->num == cut)
		(*lst)->prev = NULL;
	while (*lst)
	{
		if ((*lst)->num == cut)
		{
			(*lst)->next = NULL;
			*lst = head;
			return ;
		}
		*lst = (*lst)->next;
	}
}

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
