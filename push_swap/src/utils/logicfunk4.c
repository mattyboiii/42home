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

	if (chunk_size(*lst, chunk) <= 2)
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
int	cozy_pos(t_node **b, t_node *hold, t_node *s_chunk)
{
	int		loop;
	int		rc;
	t_node	*num_lst;
	t_node	*head;
	t_node	*copy;

	loop = 4;
	rc = 0;
	num_lst = two_ops(s_chunk, hold);
	head = num_lst;
	copy = copy_lst(b);
	rev_machine(&copy, 2, 0);
	while (loop > 0)
	{
		while (num_lst)
		{
			if (copy->num == num_lst->num)
				rc++;
			num_lst = num_lst->next;
		}
		num_lst = head;
		r(&copy, 0);
		loop--;
	}
	return (rc);
}

t_node	*two_ops(t_node *lst, t_node *hold)
{
	int		cut;
	int		rc;
	t_node	*old_next;
	t_node	*num_lst;

	rc = 4;
	cut = make_chunk_circle(&lst, &old_next, lst->chunk);
	while (lst->num != hold->num)
		lst = lst->next;
	lst = lst->prev->prev;
	while (rc > 0)
	{
		if (lst->num != hold->num)
		{
			ft_lstadd_back(&num_lst, ft_lstnew(lst->num, lst->pos, lst->stack[0]));
			rc--;
		}
		lst = lst->next;
	}
	cut_circle(&lst, old_next, cut);
	return (num_lst);
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
