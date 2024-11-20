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
int	order_check(t_node **lst, int chunk)
{
	int		cut;
	t_node	*big;
	t_node	*comp;
	t_node	*old_next;

	if (chunk_size_f(*lst, chunk) <= 2)
		return (1);
	set_big_small(lst, &big, 0);
	cut = make_chunk_circle(lst, &old_next, chunk);
	comp = big->next;
	while (comp != big && comp->chunk == chunk)
	{

		if (comp->num > comp->prev->num)
		{
			cut_circle(lst, old_next, cut);
			return (0);
		}
		comp = comp->next;
	}
	cut_circle(lst, old_next, cut);
	return (1);
}

// for now, i am just going to check if the number is within 2 next or prev
// rc = rotate count.

int	order_rot_push(t_node **b, t_node *hold, int chunk)
{
	int		rot;
	t_node	*node;
	t_node	*bcopy;

	if (chunk_size(*b, chunk) < 2)
		return (0);
	bcopy = copy_lst(b);
	node = copy_node(hold);
	rot = 0;
	node->chunk = chunk;
	pb(&node, &bcopy, 0);
	while (order_check(&bcopy, chunk) == 0 && rot < bcopy->div)
 	{
		if ((*b)->num == node->num)
			pa(&node, &bcopy, 0);
		if (bcopy->chunk != chunk)
			rot += bcopy->div;
		r(&bcopy, 0);
		rot++;
		pb(&node, &bcopy, 0);
	}
	ft_lstclear(&bcopy);
	ft_lstclear(&node);
	return (rot);
}

int	order_rev_push(t_node **b, t_node *hold, int chunk)
{
	int		rev;
	t_node	*node;
	t_node	*bcopy;

	if (chunk_size(*b, chunk) < 2)
		return (0);
	bcopy = copy_lst(b);
	node = copy_node(hold);
	rev = 0;
	node->chunk = chunk;
	pb(&node, &bcopy, 0);
	while (order_check(&bcopy, chunk) == 0 && rev < bcopy->div)
 	{
		if ((*b)->num == node->num)
			pa(&node, &bcopy, 0);
		if (bcopy->chunk != chunk)
			rev += bcopy->div;
		rrs(&bcopy, 0);
		rev++;
		pb(&node, &bcopy, 0);
	}
	ft_lstclear(&bcopy);
	ft_lstclear(&node);
	return (rev);
}
