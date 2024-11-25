/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 00:49:09 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-25 00:49:09 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	stacklst_dup(t_stacks stack)
{
	t_stacks	stk;
	stk.a = NULL;
	stk.b = NULL;
	stk.a = copy_lst(stack.a);
	stk.b = copy_lst(stack.b);
	stk.asize = stack.asize;
	stk.bsize = stack.bsize;
	return (stk);
}

void	stacklst_del(t_stacks *stack)
{
	ft_lstclear(&stack->a);
	ft_lstclear(&stack->b);
}
