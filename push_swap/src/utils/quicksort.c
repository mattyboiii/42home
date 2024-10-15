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

void	numswap(t_node **bigger, t_node **smaller, t_node **pivot, int n)
{
	int		swap;

	swap = (*bigger)->num;
	(*bigger)->num = (*smaller)->num;
	(*smaller)->num = swap;
	if (n == 1)
	{
		*pivot = *bigger;
	}
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

void	check_variables(t_node *lst, t_node **pivot, t_node **start, t_node **stop)
{
	if (*start == NULL)
		*start = lst;
	else if (*start)
		lst = *start;
	if (*stop == NULL)
		*stop = ft_lstlast(lst);
	if (*pivot == NULL)
		*pivot = ft_lstlast(lst);
}

t_node	*quicksort(t_node *lst, t_node *pivot, t_node *prev_pivot, t_node *start, t_node *stop)
{
	t_node		*bigger;

	check_variables(lst, &pivot, &start, &stop);
	print_lstnums(start);
	bigger = lst;
	while (lst->next->next != NULL && lst->next != stop)
	{
		if (lst->num < pivot->num && lst->num != bigger->num)
		{
			numswap(&bigger, &lst, &pivot, 0);
			bigger = bigger->next;
			print_lstnums(start);
		}
		lst = lst->next;
	}
	print_lstnums(start);
	if (bigger->next->num < bigger->num)
		numswap(&bigger, &bigger->next, &pivot, 0);
	print_lstnums(start);
	if (bigger->num < pivot->num)
		numswap(&bigger->next, &pivot, &pivot, 1);
	else if (bigger->num > pivot->num)
		numswap(&bigger, &pivot, &pivot, 1);
	lst = get_head(pivot);
	print_lstnums(start);
	while (is_sorted(lst, lst, stop) == 0)
		quicksort_pivot(lst, start, pivot);
	return (get_head(lst));
}

void	quicksort_pivot(t_node *lst, t_node *start, t_node *prev_pivot)
{
	t_node				*new_pivot;
	t_node				*lastnode;
	static t_node		*og_pivot;

	lastnode = ft_lstlast(lst);
	if (og_pivot == NULL)
		og_pivot = prev_pivot;
	if (lst == prev_pivot || prev_pivot > og_pivot)
		prev_pivot = og_pivot;
	if (is_sorted(lst, start, prev_pivot) == 0)
	{
		new_pivot = prev_pivot->prev;
		lst = quicksort(lst, new_pivot, prev_pivot, start, prev_pivot);
	}
	else
	{
		if (start->num <= og_pivot->num)
			start = og_pivot->next;
		new_pivot = ft_lstlast(lst)->prev;
		if (new_pivot->num > new_pivot->next->num)
			numswap(&new_pivot, &new_pivot->next, &new_pivot, 0);
		og_pivot = ft_lstlast(lst);
		lst = quicksort(lst, new_pivot, prev_pivot, start, ft_lstlast(lst));
	}
}
