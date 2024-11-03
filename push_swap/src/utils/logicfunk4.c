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
int	order_check(t_node *a, t_node *b, int chunk)
{
	t_node	*big;
	t_node	*small;
	t_node	*comp;
	t_node	*cut;

	comp = small->next;
	cut = make_circle_lst(&b);
	set_big_small(&b, &big, &small);
	while (comp != small)
	{
		if (comp->num < comp->prev)
			return (0);
		else
			comp = comp->next;

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
