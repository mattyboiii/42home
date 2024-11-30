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

/*
rot_checks_rotate - will, look for the hold number and ensure that the b stack
is ready to accept the number. Meaning ensure if hold is pushed, it will be in
the right position within the stack b. It also uses rr depending on if the top
number in stack a is hold, or at least a number <= Divider number. This function
will only use rotate operations.
*/

int	rot_checks_rotate(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 0)
		rr(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 1)
		r(&stk->a, out);
	else if (stk->a->num == hold->num && if_push(*stk, hold) == 0)
		r(&stk->b, out);
	return (1);
}

/*
rev_checks_rotate - is the same as rot_checks_rotate, but it only uses reverse
rotate
operations.
*/
int	rev_checks_rotate(t_stacks *stk, t_node *hold, int out)
{
	if (stk->a->num <= stk->a->div && if_push(*stk, stk->a) == 1)
		pb(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 0)
		rrr(stk, out);
	else if (stk->a->num != hold->num && if_push(*stk, hold) == 1)
		rrs(&stk->a, out);
	else if (stk->a->num == hold->num && if_push(*stk, hold) == 0)
		rrs(&stk->b, out);
	return (1);
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
