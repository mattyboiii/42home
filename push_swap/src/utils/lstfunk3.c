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

void	numswap(t_node *bigger, t_node *smaller)
{
	int		swap;

	swap = bigger->num;
	bigger->num = smaller->num;
	smaller->num = swap;
}

int	sorted(t_node *lst)
{
	t_node	*head;

	head = lst;
	while (lst->next != NULL)
	{
		if (lst->next->num > lst->num)
			lst = lst->next;
		else
			return (0);
	}
	lst = head;
	return (1);
}

t_node	*ft_quicksort(t_node *lst)
{
	t_node		*bigger;
	t_node		*pivot;

	bigger = lst;
	pivot = ft_lstlast(lst);
	while (lst->next != NULL && lst->num)
	{
		if (lst->num < pivot->num)
		{
			numswap(bigger, lst);
			bigger = bigger->next;
		}
		lst = lst->next;
	}
	if (bigger->num > pivot->num)
		numswap(bigger, pivot);
	pivot = bigger;

	return (get_head(lst));
}

t_node	*ft_quicksort_left(t_node *lst, int prev_pivot)
{

}

t_node	*ft_quicksort_right(t_node *lst, int prev_pivot)
{
	
}
