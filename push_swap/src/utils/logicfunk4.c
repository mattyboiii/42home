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

int	pb_rot_push(t_node *node, t_node **b, int chunk)
{
	int		rot;
	int		push_num;

	rot = 0;
	push_num = node->num;
	node->chunk = chunk;
	pb(&node, b, 0);
	while (order_check(b, chunk) == 0)
	{
		if ((*b)->num == push_num)
			pa(&node, b, 0);
		r(b, 0);
		rot++;
		node->chunk = chunk;
		pb(&node, b, 0);
	}
	pa(&node, b, 0);
	rev_machine(b, rot, 0);
	return (rot);
}

int	pb_rev_push(t_node *node, t_node **b, int chunk)
{
	int		rev;
	int		push_num;

	rev = 0;
	push_num = node->num;
	node->chunk = chunk;
	pb(&node, b, 0);
	while (order_check(b, chunk) == 0)
	{
		if ((*b)->num == push_num)
			pa(&node, b, 0);
		rrs(b, 0);
		rev++;
		node->chunk = chunk;
		pb(&node, b, 0);
	}
	pa(&node, b, 0);
	rot_machine(b, rev, 0);
	return (rev);
}

int	make_chunk_circle(t_node **lst, t_node **old_next, int chunk)
{
	t_node	*last;

	last = lstlast_chunk(*lst, chunk);
	*old_next = last->next;
	(*lst)->prev = last;
	last->next = *lst;
	return (last->num);
}

void	cut_circle(t_node **lst, t_node *old_next, int cut)
{
	t_node *head;

	head = *lst;
	if (*lst == NULL)
		return ;
	if ((*lst)->prev->num == cut)
		(*lst)->prev = NULL;
	while (*lst)
	{
		if ((*lst)->num == cut)
		{
			(*lst)->next = old_next;
			*lst = head;
			return ;
		}
		*lst = (*lst)->next;
	}
}
