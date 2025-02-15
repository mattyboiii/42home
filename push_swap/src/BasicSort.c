/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:33:29 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:32:04 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//about to update the logic. It wont use midpoint algorythm

void	set_big_small(t_node *lst, t_node **big, t_node **small)
{
	t_node	*head;

	head = lst;
	if (small)
		*small = lst;
	if (big)
		*big = lst;
	while (small && lst->next)
	{
		lst = lst->next;
		if (lst->num < (*small)->num)
			*small = lst;
	}
	lst = head;
	while (big && lst->next)
	{
		lst = lst->next;
		if (lst->num > (*big)->num)
			*big = lst;
	}
}

void	sort3(t_node **lst)
{
	t_node		*small;
	t_node		*big;

	if (sorted_asc(*lst, *lst, 0) == 1)
		return ;
	set_big_small(*lst, &big, &small);
	if (small->pos == 1 && big->pos == 2)
		s(lst, 1);
	else if (small->pos == 1 && big->pos == 0)
		r(lst, 1);
	else if (small->pos == 2 && big->pos == 1)
		rrs(lst, 1);
	else if (small->pos == 0 && big->pos == 1)
	{
		s(lst, 1);
		r(lst, 1);
	}
	else
	{
		s(lst, 1);
		rrs(lst, 1);
	}
}

void	sort5(t_stacks m)
{
	int			midnum;
	t_node		*small;
	t_node		*big;

	set_big_small(m.a, &big, &small);
	midnum = get_midnode(m.a)->num;
	while (m.asize > 3)
	{
		if (m.a->num < midnum || m.a == big)
			pb(&m, 1);
		if (ft_lstlast(m.a)->num < midnum || ft_lstlast(m.a)->num == big->num)
			rrs(&m.a, 1);
		else if (m.a->num >= midnum && m.a->num < big->num)
			r(&m.a, 1);
	}
	sort3(&m.a);
	while (sorted_asc(m.a, m.a, 0) == 0 || m.b)
	{
		if (sorted_asc(m.a, m.a, 0) == 1 && m.b)
			pa(&m, 1);
		if (m.a->num > ft_lstlast(m.a)->num)
			r(&m.a, 1);
		else if (m.a->num < get_node(m.a, 2)->num && m.a->num > m.a->next->num)
			s(&m.a, 1);
	}
}

t_node	*get_midnode(t_node *lst)
{
	t_node	*sorted;
	t_node	*midnode;
	t_node	*last;
	t_node	*out;

	sorted = NULL;
	out = lst;
	if (ft_lstsize(lst) <= 2 || lst->next == NULL)
		return (lst);
	sorted = simple_sort(copy_lst(lst));
	last = ft_lstlast(sorted);
	midnode = get_node(sorted, (last->pos + 1) / 2);
	while (out && out->num != midnode->num)
		out = out->next;
	ft_lstclear(&sorted);
	last = NULL;
	midnode = NULL;
	return (out);
}
