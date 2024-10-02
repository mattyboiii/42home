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

void	ss(t_node *a, t_node *b)
{
	s(a);
	s(b);
}

void	rr(t_node *a, t_node *b)
{
	r(a);
	r(b);
}

void	rrs(t_node *node)
{
	int		swap;
	t_node	*last;

	if (node == NULL)
		return ;
	last = ft_lstlast(node);
	swap = node->num;
	node->num = last->num;
	last->num = swap;
}

void	rrr(t_node *a, t_node *b)
{
	rrs(a);
	rrs(b);
}
