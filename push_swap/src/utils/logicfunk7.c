/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 01:47:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-17 01:47:50 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cozy_pos(t_node **b, t_node *hold, t_node *s_chunk)
{
	int		loop;
	int		rotate;
	t_node	*num_lst;
	t_node	*head;
	t_node	*copy;

	loop = 4;
	num_lst = two_ops(s_chunk, hold);
	head = num_lst;
	copy = copy_lst(b);
	rev_machine(&copy, 2, 0);
	rotate = cozy_pos_rotate(copy, num_lst, head, loop);
	ft_lstclear(&num_lst);
	ft_lstclear(&copy);
	return (rotate);
}

int	cozy_pos_rotate(t_node *b_copy, t_node *num_lst, t_node *num_head, int loop)
{
	int		rotate;

	rotate = 0;
	while (loop > 0)
	{
		while (num_lst)
		{
			if (b_copy->num == num_lst->num)
				rotate++;
			num_lst = num_lst->next;
		}
		num_lst = num_head;
		r(&b_copy, 0);
		loop--;
	}
	return (rotate);
}


int	cozy_rot_push(t_node **b, t_node *hold, t_node *s_chunk, int range)
{
	int		rot;
	int		size;

	rot = 0;
	hold->chunk = s_chunk->chunk;
	size = chunk_size(b, s_chunk->chunk);
	if (size < range)
		range = size - 1;
	while (cozy_pos(b, hold, s_chunk) <= range)
	{
		r(b, 0);
		rot++;
	}
	rev_machine(b, rot, 0);
	return (rot);
}

int	cozy_rev_push(t_node **b, t_node *hold, t_node *s_chunk, int range)
{
	int		rev;

	rev = 0;
	hold->chunk = s_chunk->chunk;
	while (cozy_pos(b, hold, s_chunk) != range)
	{
		rrs(b, 0);
		rev++;
	}
	rot_machine(b, rev, 0);
	return (rev);
}

t_node	*two_ops(t_node *lst, t_node *hold)
{
	int		cut;
	int		rotate;
	t_node	*old_next;
	t_node	*num_lst;

	num_lst = NULL;
	rotate = 4;
	cut = make_chunk_circle(&lst, &old_next, lst->chunk);
	while (lst->num != hold->num)
		lst = lst->next;
	lst = lst->prev->prev;
	while (rotate > 0)
	{
		if (lst->num != hold->num)
		{
			ft_lstadd_back(&num_lst, ft_lstnew(lst->num, lst->pos, lst->stack[0]));
			rotate--;
		}
		lst = lst->next;
	}
	cut_circle(&lst, old_next, cut);
	return (num_lst);
}
