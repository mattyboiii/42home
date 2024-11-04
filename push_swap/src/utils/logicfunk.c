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

int	check_pb(t_node **a, t_node **b, int chunk)
{
	int		rotates;
	t_node	*big;
	t_node	*small;

	rotates = 0;
	if (chunk_size(b, chunk) < 2)
		return ;
	set_big_small(&b, &big, &small);
	pb(a, b, 0);
	while (order_check(*b, chunk) == 0)
	{
		pa(a, b, 0);
		r(b, 0);
		pb(a, b, 0);
		rotates++;
	}
	// use my order check function, to constantly check the order given im about
	// to push the number into the array.
	// my idea is that. I can place them inside the stack immediately, but this




}

void	ra_or_rra(t_node **a, t_node **b, int chunk, int chunk_div)
{
	int		ra_rra;
	t_node	*hold_a;
	t_node	*hold_b;

	hold_a = hold_first(*a, chunk_div);
	hold_b = hold_second(*a, chunk_div);
	print_lstnums(*a, *b);
	ra_rra = compare_holds(*a, hold_a, hold_b, chunk_div);
	if (hold_a && ra_rra == 0)
		while (*a != hold_a)
			r(a, 1);
	else if (hold_b && ra_rra == 1)
		while (*a != hold_b)
			rrs(a, 1);
	(*a)->chunk = chunk;
	//check_pb(a, b, chunk);
	pb(a, b, 1);
	print_lstnums(*a, *b);
}

void	sort_to_b(t_node **a, t_node **b)
{
	int		chunk_div;
	int		chunk_add;
	int		chunk;

	chunk = 1;
	chunk_div = get_chunk_number(*a);
	chunk_add = chunk_div;
	while (chunk_size(*a, 0) > 5)
	{
		while (check_lg_sm(*a, chunk_div + 1, chunk, 0) == 1)
			ra_or_rra(a, b, chunk, chunk_div);
		chunk++;
		chunk_div = chunk_div + chunk_add + 1;
	}
}
