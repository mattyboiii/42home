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

void	check_logic(char *cur_act)
{
	static char	*pre_act;

	pre_act = "hello";
	ft_putendl_fd(pre_act, 1);
	ft_putendl_fd(cur_act, 1);
}

void	s(t_node *node, int print)
{
	int		swap;

	if (node == NULL || node->next == NULL)
		return ;
	swap = node->num;
	node->num = node->next->num;
	node->next->num = swap;
	if (print == 1)
	{
		ft_putchar_fd('s', 1);
		ft_putendl_fd(node->stack, 1);
	}
}

void	r(t_node *node, int print)
{
	int		swap;
	t_node	*last;

	if (node == NULL || node->next == NULL)
		return ;
	last = ft_lstlast(node);
	swap = node->num;
	node->num = last->num;
	last->num = swap;
	if (print == 1)
	{
		ft_putchar_fd('r', 1);
		ft_putendl_fd(node->stack, 1);
	}
}


void	pa(t_node **a, t_node **b, int	print)
{
	t_node	*bhead;

	bhead = NULL;
	if (!(*b))
		return ;
	bhead = ft_nodedel(*b);
	*b = (*b)->next;
	bhead->stack[0] = 'a';
	ft_lstadd_front(a, bhead);
	ft_stackposupdate(*a);
	if (print == 1)
		ft_putendl_fd("pa", 1);
}

void	pb(t_node **a, t_node **b, int print)
{
	t_node	*ahead;

	ahead = NULL;
	if (!(*a))
		return ;
	ahead = ft_nodedel(*a);
	*a = (*a)->next;
	ahead->stack[0] = 'b';
	ft_lstadd_front(b, ahead);
	ft_stackposupdate(*b);
	if (print == 1)
		ft_putendl_fd("pb", 1);
}
