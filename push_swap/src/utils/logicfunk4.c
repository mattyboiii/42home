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

// comp = compare
int	order_check(t_node *lst, int chunk)
{
	t_node	*small;
	t_node	*comp;
	t_node	*cut;

	set_big_small(&lst, 0, &small);
	comp = small->next;
	cut = make_circle_lst(&lst);
	while (comp != small)
	{
		if (comp->num < comp->prev->num)
		{
			cut_circle(&lst, cut);
			return (0);
		}
		comp = comp->next;
	}
	cut_circle(&lst, cut);
	return (1);
}

void	cut_circle(t_node **lst, t_node *cut)
{
	if (*lst == NULL)
		return ;
	if ((*lst)->prev == cut)
		(*lst)->prev == NULL;
	while (*lst)
	{
		if (*lst == cut)
		{
			(*lst)->next == NULL;
			return ;
		}
		*lst = (*lst)->next;
	}
}

t_node	*make_circle_lst(t_node **lst)
{
	t_node	*last;

	last = ft_lstlast(*lst);
	(*lst)->prev = last;
	last->next = *lst;
	return (last);
}
