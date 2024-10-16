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

void	ss(t_node **a, t_node **b)
{
	s(a, 0);
	s(b, 0);
	ft_putendl_fd("ss", 1);
}

void	rr(t_node **a, t_node **b)
{
	r(a, 0);
	r(b, 0);
	ft_putendl_fd("rr", 1);
}

void	rrs(t_node **lst, int print)
{
	int		swap;
	t_node	*first;
	t_node	*last;
	t_node	*last_prev;
// bottom number goes to the top, pushing others down.
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	last = ft_lstlast(*lst);
	last_prev = last->prev;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	last_prev->next = NULL;
	*lst = last;
	ft_stackposupdate(get_head(*lst));
	if (print == 1)
	{
		ft_putstr_fd("rr", 1);
		ft_putendl_fd((*lst)->stack, 1);
	}
}

void	rrr(t_node **a, t_node **b)
{
	rrs(a, 0);
	rrs(b, 0);
	ft_putendl_fd("rrr", 1);
}
