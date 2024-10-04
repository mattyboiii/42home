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
/*
void	checklogic(char *cur_act)
{
	static char *pre_act;
}
*/
void	s(t_node *node)
{
	int		swap;

	if (node == NULL || node->next == NULL)
		return ;
	swap = node->num;
	node->num = node->next->num;
	node->next->num = swap;
}

void	r(t_node *node)
{
	int		swap;
	t_node	*last;

	if (node == NULL || node->next == NULL)
		return ;
	last = ft_lstlast(node);
	swap = node->num;
	node->num = last->num;
	last->num = swap;
	
}


void	pa(t_node **a, t_node **b)
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
}

void	pb(t_node **a, t_node **b)
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
}
