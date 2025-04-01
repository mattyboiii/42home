/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:49:12 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:25:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief rotate the lst/stack handed in.
 */
int	r(t_node **lst, int print)
{
	t_node	*swapnode;
	t_node	*last;

	swapnode = *lst;
	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
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
	return (1);
}

/**
 * @brief push number at top of b to a
 */
int	pa(t_stacks *stack, int print)
{
	t_node	*ahead;

	ahead = NULL;
	if (!stack->b)
		return (0);
	ahead = ft_nodedel(stack->b);
	stack->b = stack->b->next;
	ahead->stack[0] = 'a';
	ft_lstadd_front(&stack->a, ahead);
	ft_stackposupdate(stack->a);
	if (print == 1)
		ft_putendl_fd("pa", 1);
	stack->asize++;
	stack->bsize--;
	return (1);
}

/**
 * @brief push number at top of a to b.
 */
int	pb(t_stacks *stack, int print)
{
	t_node	*ahead;

	ahead = NULL;
	if (!stack->a)
		return (0);
	ahead = ft_nodedel(stack->a);
	stack->a = stack->a->next;
	ahead->stack[0] = 'b';
	ft_lstadd_front(&stack->b, ahead);
	ft_stackposupdate(stack->b);
	if (print == 1)
		ft_putendl_fd("pb", 1);
	stack->asize--;
	stack->bsize++;
	return (1);
}
