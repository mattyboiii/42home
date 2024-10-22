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

int	check_lg_sm(t_node *lst, int compare, int chunk, int lg_sm)
{
	t_node	*node;

	node = lst;
	if (lg_sm == 0)
	{
		while (node)
		{
			if (node->chunk != chunk)
				node = node->next;
			if (node->num < compare)
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

void	compare_bottom_num(t_node **a, t_node **b, int chunk, int lg_sm)
{
	int		current;
	t_node	*last;

	if (*a == NULL || *b == NULL)
		return ;
	current = (*b)->num;
	last = ft_lstlast(*b);
	if (lg_sm == 1)
	{
		if ((last->num > current && last->chunk == chunk) && (check_lg_sm(*b,
					last->num, chunk, lg_sm) == 0))
		{
			rrs(b, 1);
			pa(a, b, 1);
		}
	}
	else
	{
		if ((last->num < current && last->chunk == chunk) && (check_lg_sm(*b,
					last->num, chunk, lg_sm) == 0))
		{
			rrs(b, 1);
			pa(a, b, 1);
		}
	}
}

void	set_big_small(t_node **lst, t_node **big, t_node **small)
{
	t_node	*head;

	head = *lst;
	*big = *lst;
	*small = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		if ((*lst)->num < (*small)->num)
			*small = *lst;
		else if ((*lst)->num > (*big)->num)
			*big = *lst;
	}
	*lst = head;
}

void	sort3(t_node **lst)
{
	t_node		*small;
	t_node		*big;

	set_big_small(lst, &big, &small);
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

t_node	*get_midnode(t_node **lst, int chunk)
{
	t_node	*sorted;
	t_node	*midnode;
	t_node	*last;
	t_node	*out;

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
