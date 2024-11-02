/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-30 02:28:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024-10-30 02:28:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_lg_sm(t_node *lst, int compare, int chunk, int lg_sm)
{
	t_node	*node;

	node = lst;
	if (lg_sm == 0)
	{
		while (node)
		{
			if (node->chunk != chunk && node->next != NULL)
				node = node->next;
			if (node && node->num < compare)
				return (1);
			node = node->next;
		}
	}
	else
	{
		while (node)
		{
			if (node->num > compare)
				return (1);
			node = node->next;
		}
	}
	return (0);
}

int	get_chunk_number(t_node *lst)
{
	int		chunk_step;
	t_node	*big;
	t_node	*small;

	set_big_small(&lst, &big, &small);
	if (ft_lstlast(lst)->pos <= 99)
		chunk_step = ((big->num - small->num) / 5);
	if (ft_lstlast(lst)->pos > 99)
		chunk_step = ((big->num - small->num) / 12);
	return (chunk_step);
}

int	compare_holds(t_node *lst, t_node *hold_a, t_node *hold_b, int chunk_div)
{
	int		ra_num;
	int		rb_num;
	t_node	*last;

	if (!hold_a && !hold_b)
		return (-1);
	if (!hold_a)
		return (1);
	if (!hold_b)
		return (0);
	last = ft_lstlast(lst);
	ra_num = hold_a->pos;
	rb_num = last->pos - hold_b->pos;
	if (ra_num > rb_num)
		if (check_lg_sm(lst, hold_a->num, 0, 0) == 0 && ra_num - rb_num <= 2)
			return (0);
	else if (ra_num < rb_num)
		if (check_lg_sm(lst, hold_b->num, 0, 0) == 0 && rb_num - ra_num <= 2)
			return (1);
	if (ra_num <= rb_num)
		return (0);
	else
		return (1);
}

t_node	*hold_first(t_node *lst, int chunk_div)
{
	int		size;
	t_node	*big;
	t_node	*small;

	set_big_small(&lst, &big, &small);
	size = ft_lstlast(lst)->pos / 2;
	while (lst && lst->pos <= size)
	{
		if (lst->num <= chunk_div)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_node	*hold_second(t_node *lst, int chunk_div)
{
	int		size;
	t_node	*big;
	t_node	*small;

	set_big_small(&lst, &big, &small);
	lst = ft_lstlast(lst);
	size = ft_lstlast(lst)->pos / 2;
	while (lst && lst->pos > size)
	{
		if (lst->num <= chunk_div)
			return (lst);
		lst = lst->prev;
	}
	return (NULL);
}

