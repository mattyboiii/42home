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

void	pb_chunk(t_node **a, t_node **b, int midnum, int chunk)
{
	t_node	*last;

	last = ft_lstlast(*a);
	while ((check_lg_sm(*a, midnum, (*a)->chunk, 0) == 1))
	{
		while ((*a)->num < midnum)
		{
			(*a)->chunk = chunk;
			pb(a, b, 1);
		}
		if (ft_lstlast(*a)->num < midnum && (*a)->num != last->num)
		{
			rrs(a, 1);
			(*a)->chunk = chunk;
			pb(a, b, 1);
		}
		if (((*a)->num > midnum || (*a)->num == midnum)
			&& (check_lg_sm(*a, midnum, (*a)->chunk, 0) == 1))
		{
			r(a, 1);
		}
	}
}

void	pa_chunk(t_node **a, t_node **b, int midnum, int chunk)
{
	int		rot;

	rot = 0;
	print_lstnums(*a, *b);
	while (*b && (*b)->chunk == chunk && neg_lst(*b, chunk) == 0)
	{
		while (*b && check_lg_sm(*b, (*b)->num, chunk, 1) == 0 && (*b)->chunk
			== chunk)
		{
			pa(a, b, 1);
		}
		compare_bottom_num(a, b, chunk, 1);
		print_lstnums(*a, *b);
		if ((*b && (*b)->chunk == chunk && if_swap(*b, chunk, 1) == 1)
			|| check_lg_sm(*b, (*b)->next->num, chunk, 1) == 0)
		{
			s(b, 1);
		}
		else if ((*b && (*b)->chunk == chunk && neg_lst(*b, chunk) == 0)
			&& check_lg_sm(*b, (*b)->num, chunk, 1) == 1)
		{
			r(b, 1);
			rot++;
		}
		print_lstnums(*a, *b);
	}
	while (*b && rot > 0 && chunk != 1 && ft_lstlast(*b)->chunk == chunk)
	{
		rrs(b, 1);
		rot--;
	}
}

void	pa_chunk_neg(t_node **a, t_node **b, int midnum, int chunk)
{
	int		rot;

	rot = 0;
	while ((*b && (check_lg_sm(*b, midnum, chunk, 1) == 1)) || (*b
			&& chunk_size(*b, chunk) <= 3))
	{
		while ((*b && check_lg_sm(*b, (*b)->num, chunk, 1) == 0))
			pa(a, b, 1);
		if ((*b && if_swap(*b, chunk, 0) == 1) || (*b && check_lg_sm(*b,
					(*b)->next->num, chunk, 1) == 0))
			s(b, 1);
		else if ((*b && (*b)->num < midnum) || (*b && (check_lg_sm(*b,
						(*b)->num, chunk, 1) == 1)))
		{
			r(b, 1);
			rot++;
		}
		compare_bottom_num(a, b, chunk, 1);
	}
	while (*b && rot > 0 && chunk != 1)
	{
		rrs(b, 1);
		rot--;
	}
}

void	sort_to_a(t_node **a, t_node **b, int *chunk)
{
	t_node		*midnode;

	while (*b)
	{
		if (*chunk == 1 && chunk_size(*b, *chunk) == 3)
			sort3(b);
		midnode = get_midnode(b, *chunk);
		if ((chunk_size(*b, *chunk) == 2))
		{
			if (*b && if_swap(*b, *chunk, 1) == 1)
				s(b, 1);
			while ((*b) && (*b)->chunk == *chunk && sorted_des(*b, *chunk) == 1)
				pa(a, b, 1);
			if (*b && *chunk > 1 && chunk_size(*b, *chunk) == 0)
				(*chunk)--;
			midnode = get_midnode(b, *chunk);
		}
		if (*b && neg_lst(*b, *chunk) == 0)
			pa_chunk(a, b, midnode->num, *chunk);
		else if (*b && neg_lst(*b, *chunk) == 1)
			pa_chunk_neg(a, b, midnode->num, *chunk);
		if (*b && *chunk > 1 && chunk_size(*b, *chunk) == 0)
			(*chunk)--;
	}
}

void	sort_to_b(t_node **a, t_node **b)
{
	int		chunk;
	t_node	*midnode;

	chunk = 0;
	while (ft_lstlast(*a)->pos > 2)
	{
		chunk++;
		midnode = get_midnode(a, 0);
		pb_chunk(a, b, midnode->num, chunk);
	}
	if (chunk_size(*a, 0) == 3)
		sort3(a);
	else if (chunk_size(*a, 0) < 3)
	{
		if (if_swap(*a, 0, 0) == 1)
			s(a, 1);
	}
	sort_to_a(a, b, &chunk);
}
