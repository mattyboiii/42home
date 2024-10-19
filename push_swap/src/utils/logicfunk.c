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
		print_lstnums(*a, *b);
		while ((*a)->num < midnum)
		{
			(*a)->chunk = chunk;
			pb(a, b, 1);
			print_lstnums(*a, *b);
		}
		if (ft_lstlast(*a)->num < midnum && (*a)->num != last->num)
		{
			rrs(a, 1);
			(*a)->chunk = chunk;
			pb(a, b, 1);
			print_lstnums(*a, *b);
		}
		if (((*a)->num > midnum || (*a)->num == midnum)
				&& (check_lg_sm(*a, midnum, (*a)->chunk, 0) == 1))
		{
			r(a, 1);
			print_lstnums(*a, *b);
		}
	}
}

void	pa_chunk(t_node **a, t_node **b, int midnum, int chunk)
{
	int		ra;

	ra = 0;
	while ((*b) && (check_lg_sm(*b, midnum, chunk, 1) == 1) && neg_lst(*b, chunk) == 0)
	{

		//check lst_neg here. If it is. change below while to start looking for the smallest number
		while ((*b)->num > midnum && check_lg_sm(*b, (*b)->num, chunk, 1) == 0)
		{
			pa(a, b, 1);
			print_lstnums(*a, *b);
		}
		if (if_swap(*b, chunk, 1) == 1 || check_lg_sm(*b, (*b)->next->num, chunk, 1) == 0)
		{
			s(b, 1);
			print_lstnums(*a, *b);
		}
		if (((*b)->num <= midnum && check_lg_sm(*b, midnum, (*b)->chunk, 1) == 1
			&& neg_lst(*b, chunk) == 0) || ((*b)->num > midnum
			&& check_lg_sm(*b, (*b)->num, chunk, 1) == 1))
		{
			r(b, 1);
			ra++;
			print_lstnums(*a, *b);
		}
	}
	while (ra > 0 && chunk != 1)
	{
		rrs(b, 1);
		ra--;
	}
}

void	pa_chunk_neg(t_node **a, t_node **b, int midnum, int chunk)
{
	int		ra;

	ra = 0;
	while ((check_lg_sm(*b, midnum, chunk, 0) == 1))
	{
		print_lstnums(*a, *b);
		while ((*b)->num < midnum && check_lg_sm(*b, (*b)->num, chunk, 1) == 0)
		{
			pa(a, b, 1);
			print_lstnums(*a, *b);
		}
		if (ft_lstlast(*b)->num < (*b)->num && check_lg_sm(*b, (*b)->num, chunk, 1) == 0)
		{
			rrs(a, 1);
			pa(a, b, 1);
			print_lstnums(*a, *b);
		}
		if (((*b)->num > midnum || (*b)->num == midnum)
				&& (check_lg_sm(*b, midnum, chunk, 0) == 1))
		{
			r(b, 1);
			print_lstnums(*a, *b);
		}
	}
}

void	sort_to_a(t_node **a, t_node **b, int *chunk)
{
	t_node		*midnode;

	while (*b)
	{
		print_lstnums(*a, *b);
		midnode = get_midnode(b, *chunk);
		if ((chunk_size(*b, *chunk) == 2))
		{
			if (if_swap(*b, *chunk, 1) == 1)
			{
				s(b, 1);
				print_lstnums(*a, *b);
			}
			while ((*b)->chunk == *chunk && sorted_des(*b, *chunk) == 1)
			{
				pa(a, b, 1);
				print_lstnums(*a, *b);
			}
			if (*chunk > 1 && chunk_size(*b, *chunk) == 0)
				(*chunk)--;
			midnode = get_midnode(b, *chunk);
		}
		if (neg_lst(*b, *chunk) == 0)
			pa_chunk(a, b, midnode->num, *chunk);
		else
			pa_chunk_neg(a, b, midnode->num, *chunk);
		print_lstnums(*a, *b);
		if (*chunk > 1 && chunk_size(*b, *chunk) == 0)
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

