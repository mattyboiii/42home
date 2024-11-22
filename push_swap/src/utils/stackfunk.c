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

void	s(t_node **lst, int print)
{
	int		swap;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	swap = (*lst)->num;
	(*lst)->num = (*lst)->next->num;
	(*lst)->next->num = swap;
	if (print == 1)
	{
		ft_putchar_fd('s', 1);
		ft_putendl_fd((*lst)->stack, 1);
	}
}

void	r(t_node **lst, int print)
{
	t_node	*swapnode;
	t_node	*last;

	swapnode = *lst;
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	swapnode = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last = ft_lstlast(*lst);
	last->next = swapnode;
	swapnode->prev = last;
	swapnode->next = NULL;
	ft_stackposupdate(*lst);
	if (print == 1)
	{
		ft_putchar_fd('r', 1);
		ft_putendl_fd((*lst)->stack, 1);
	}
}

void	pa(t_stacks *stack, int print)
{
	t_node	*ahead;

	ahead = NULL;
	if (!stack->a)
		return ;
	ahead = ft_nodedel(stack->b);
	stack->b = stack->b->next;
	ahead->stack[0] = 'a';
	ft_lstadd_front(&stack->a, ahead);
	ft_stackposupdate(stack->a);
	if (print == 1)
		ft_putendl_fd("pb", 1);
	stack->asize++;
	stack->bsize--;
}

void	pb(t_stacks *stack, int print)
{
	t_node	*ahead;

	ahead = NULL;
	if (!stack->a)
		return ;
	ahead = ft_nodedel(stack->a);
	stack->a = stack->a->next;
	ahead->stack[0] = 'b';
	ft_lstadd_front(&stack->b, ahead);
	ft_stackposupdate(stack->b);
	if (print == 1)
		ft_putendl_fd("pb", 1);
	stack->asize--;
	stack->bsize++;
}
