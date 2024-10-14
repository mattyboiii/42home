/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-30 12:48:08 by mtripodi          #+#    #+#             */
/*   Updated: 2024-09-30 12:48:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	numswap(t_node **bigger, t_node **smaller, int n)
{
	int		swap;
	t_node	*swapnode;

	swap = (*bigger)->num;
	(*bigger)->num = (*smaller)->num;
	(*smaller)->num = swap;

	if (n == 1)
		*smaller = *bigger;
}


int	is_sorted(t_node *lst, t_node *start, t_node *stop)
{
	t_node	*head;

	head = lst;
	while (lst != start)
		lst = lst->next;
	while (lst->next != NULL && lst != stop)
	{
		if (lst->num > lst->next->num)
		{
			lst = head;
			return (0);
		}
		lst = lst->next;
	}
	lst = head;
	return (1);
}

t_node	*get_node(t_node *lst, int index)
{
	t_node	*node;

	node = lst;
	if (lst == NULL)
		return (NULL);
	while (node->pos < index && node->next != NULL)
		node = node->next;
	return (node);
}

void	print_lstnums(t_node *lst)
{
	int		i;
	t_node	*head;

	head = lst;
	i = 0;
	while (lst)
	{
		ft_printf("index [%d]: %d\n", i, lst->num);
		i++;
		lst = lst->next;
	}
	ft_putchar_fd('\n', 1);
}

t_node	*quicksort(t_node *lst, t_node *pivot, t_node *prev_pivot, t_node *stop)
{
	t_node		*bigger;

	bigger = lst;
	if (stop == NULL)
		stop = ft_lstlast(lst);
	if (pivot == NULL)
		pivot = ft_lstlast(lst);
	print_lstnums(lst);
	while (lst->next->next != NULL && lst->next != stop)
	{
		if (lst->num < pivot->num && lst->num != bigger->num)
		{
			numswap(&bigger, &lst, 0);
			bigger = bigger->next;
			print_lstnums(get_head(lst));
		}
		lst = lst->next;
	}
	print_lstnums(get_head(lst));
	if (bigger->num < pivot->num)
		numswap(&bigger->next, &pivot, 1);
	else if (bigger->num > pivot->num)
		numswap(&bigger, &pivot, 1);
	lst = get_head(lst);
	print_lstnums(lst);
	while (is_sorted(lst, lst, stop) == 0)
		quicksort_pivot(lst, lst, pivot);
	return (get_head(lst));
}

void	quicksort_pivot(t_node *lst, t_node *smallest, t_node *prev_pivot)
{
	t_node				*new_pivot;
	t_node				*lastnode;
	static t_node		*og_pivot;

	lastnode = ft_lstlast(lst);
	if (og_pivot == NULL)
		og_pivot = prev_pivot;
	if (lst == prev_pivot || prev_pivot > og_pivot)
		prev_pivot = og_pivot;
	if (is_sorted(lst, lst, prev_pivot) == 0)
	{
		new_pivot = get_node(lst, (prev_pivot->pos - 1));
		lst = quicksort(lst, new_pivot, prev_pivot, prev_pivot);
	}
	else
	{
		smallest = og_pivot;
		og_pivot = get_node(lst, lastnode);
		/*
		if (is_sorted(lst, smallest, lastnode) == 0)
		{
			lst = prev_pivot->next;
			new_pivot = get_node(lst, (lastnode->pos - 1));
			numswap(&lastnode, &new_pivot, 1);
			lst = quicksort(smallest, new_pivot, prev_pivot, lastnode);
		}
		*/
	}
}
