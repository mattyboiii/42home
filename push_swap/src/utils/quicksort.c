/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                         :+:      :+:    :+:   */
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

t_node	*simple_sort(t_node *lst)
{
	t_node	*current;
	t_node	*next_node;
	t_node	*head;

	head = lst;
	if (!lst)
		return (NULL);

	current = lst;
	while (current->next)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->num > next_node->num)
				numswap(current, next_node);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (head);
}
