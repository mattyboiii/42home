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

t_node	*get_midnode(t_node **lst, int chunk)
{
	t_node	*sorted;
	t_node	*midnode;
	t_node	*last;
	t_node	*out;
	t_node	*chunklast;

	sorted = NULL;
	out = *lst;
	if (chunk_size(*lst, chunk) <= 2 || (*lst)->next == NULL)
		return (*lst);
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
	t_node	*last;

	last = ft_lstlast(*a);
	while ((check_lg_sm(*a, midnode->num, (*a)->chunk, 0) == 1))
	{
		while ((*a)->num < midnode->num)
		{
			(*a)->chunk = chunk;
			pb(a, b, 1);
		}
		if (ft_lstlast(*a)->num < midnode->num && (*a)->num != last->num)
		{
			rrs(a, 1);
			(*a)->chunk = chunk;
			pb(a, b, 1);
		}
		while (((*a)->num > midnode->num || (*a)->num == midnode->num)
				&& (check_lg_sm(*a, midnode->num, (*a)->chunk, 0) == 1))
			r(a, 1);
	}
}

void	pa_chunk(t_node **a, t_node **b, t_node *midnode, int chunk)
{
	int		ra;

	ra = 0;
	while ((*b) && (check_lg_sm(*b, midnode->num, (*b)->chunk, 1) == 1))
	{
		while ((*b)->num > midnode->num)
			pa(a, b, 1);
		if (if_swap(*b, chunk) == 1)
			s(b, 1);
		while ((*b)->num <= midnode->num && check_lg_sm(*b, midnode->num,
			(*b)->chunk, 1) == 1)
		{
			r(b, 1);
			ra++;
		}
		while ((*b) && sorted_des(*b, chunk) == 1)
			pa(a, b, 1);
	}
	while (ra > 0)
	{
		rrs(b, 1);
		ra--;
	}
}

void	sort_to_a(t_node **a, t_node **b, int *chunk)
{
	t_node		*midnode;

	while (*b)
	{
		print_lstnums(*a, *b);
		midnode = get_midnode(b, *chunk);
		if ((chunk_size(*b, *chunk) <= 2))
		{
			while ((*b)->chunk == *chunk)
				pa(a, b, 1);
			(*chunk)--;
			midnode = get_midnode(b, *chunk);
		}
		pa_chunk(a, b, midnode, *chunk);
		if (*chunk > 1)
			(*chunk)--;
	}
}

void	sort_to_b(t_node **a, t_node **b)
{
	int		chunk;
	t_node	*midnode;

	chunk = 0;
	while (ft_lstlast(*a)->pos > 1)
	{
		chunk++;
		midnode = get_midnode(a, 0);
		pb_chunk(a, b, midnode, chunk);
	}
	if (sorted_asc(*a, *a, (*a)->chunk) == 0)
		s(a, 1);
	sort_to_a(a, b, &chunk);
}

