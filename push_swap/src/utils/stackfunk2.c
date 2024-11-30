/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:49:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:49:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	s(t_node **lst, int print)
{
	int		swap;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	swap = (*lst)->num;
	(*lst)->num = (*lst)->next->num;
	(*lst)->next->num = swap;
	if (print == 1)
	{
		ft_putchar_fd('s', 1);
		ft_putendl_fd((*lst)->stack, 1);
	}
	return (1);
}

int	ss(t_stacks *stack, int print)
{
	s(&stack->a, 0);
	s(&stack->b, 0);
	if (print == 1)
		ft_putendl_fd("ss", 1);
	return (1);
}

int	rr(t_stacks *stack, int print)
{
	r(&stack->a, 0);
	r(&stack->b, 0);
	if (print == 1)
		ft_putendl_fd("rr", 1);
	return (1);
}

int	rrr(t_stacks *stack, int print)
{
	rrs(&stack->a, 0);
	rrs(&stack->b, 0);
	if (print == 1)
		ft_putendl_fd("rrr", 1);
	return (1);
}

int	rrs(t_node **lst, int print)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_prev;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	first = *lst;
	last = ft_lstlast(*lst);
	last_prev = last->prev;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	last_prev->next = NULL;
	*lst = last;
	ft_stackposupdate(*lst);
	if (print == 1)
	{
		ft_putstr_fd("rr", 1);
		ft_putendl_fd((*lst)->stack, 1);
	}
	return (1);
}

