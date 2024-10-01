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

t_node	*fill_a(char **arv)
{
	int			i;
	int			j;
	t_node		*lst;
	t_node		*node;

	i = 0;
	j = 0;
	lst = NULL;
	while (arv[i] && arv[i + j])
	{
		if (arv[i][0] == '/')
		{
			node = ft_lstnew(ft_atoi(arv[i + 1]), i);
			j++;
		}
		else
			node = ft_lstnew(ft_atoi(arv[i + j]), i);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

void	sa(t_node *node)
{
	int		swap;

	if (node == NULL || node->next == NULL)
		return ;
	swap = node->num;
	node->num = node->next->num;
	node->next->num = swap;
}

void	ra(t_node *node)
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
	ft_lstadd_front(b, bhead);
	ft_stackposupdate(*b);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*ahead;

	ahead = NULL;
	if (!(*a))
		return ;
	ahead = ft_nodedel(*a);
	*a = (*a)->next;
	ft_lstadd_front(b, ahead);
	ft_stackposupdate(*b);
}
