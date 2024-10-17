/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-04 07:33:29 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_node	*get_midnode(t_node **lst, int	chunk)
{
	t_node	*sorted;
	t_node	*midnode;
	t_node	*last;
	t_node	*out;

	sorted = NULL;
	out = *lst;
	sorted = simple_sort(copy_lst(lst, chunk));
	last = ft_lstlast(sorted);
	midnode = get_node(sorted, (last->pos + 1) / 2);
	while (out && out->num != midnode->num)
		out = out->next;
	ft_lstclear(&sorted);
	last = NULL;
	midnode = NULL;
	return (out);
}

void	pb_chunk(t_node **a, t_node **b, t_node *midnode, int chunk)
{
		while ((*a)->pos != ft_lstlast(*a)->pos)
		{
			while ((*a)->num < midnode->num)
			{
				(*a)->chunk = chunk;
				pb(a, b, 1);
				print_lstnums(*a, *b);
			}
			if (ft_lstlast(*a)->num < midnode->num)
			{
				rrs(a, 1);
				(*a)->chunk = chunk;
				pb(a, b, 1);
				print_lstnums(*a, *b);
			}
			while ((*a)->num > midnode->num || (*a)->num == midnode->num)
			{
				r(a, 1);
				print_lstnums(*a, *b);
			}
		}
		if ((*a)->num < midnode->num)
		{
			(*a)->chunk = chunk;
			pb(a, b, 1);
			print_lstnums(*a, *b);
		}
}

void	sort_to_b(t_node **a, t_node **b, int	*chunk)
{

	t_node	*midnode;

	while (ft_lstlast(*a)->pos > 2)
	{
		(*chunk)++;
		midnode = get_midnode(a, 0);
		pb_chunk(a, b, midnode, *chunk);
	}
}

void	sort_to_a(t_node **a, t_node **b)
{

}

void	sort(t_node **a, t_node **b)
{
	int		chunk;

	chunk = 0;
	sort_to_b(a, b, &chunk);
}



