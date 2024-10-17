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

void	numswap(t_node *bigger, t_node *smaller)
{
	int		swap;

	swap = bigger->num;
	bigger->num = smaller->num;
	smaller->num = swap;
}

/*
void	print_lstnums(t_node *a, t_node *b)
{
	int		i;
	t_node	*list_a;
	t_node	*list_b;

	list_a = a;
	list_b = b;
	i = 0;
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_printf("a[%d]: %d", i, list_a->num);
			list_a = list_a->next;
		}
		if (list_b)
		{
			ft_printf("  -----  b[%d]: %d", i, list_b->num);
			list_b = list_b->next;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
*/

void	print_lstnums(t_node *a, t_node *b)
{
	int		i;
	t_node	*list_a;
	t_node	*list_b;

	list_a = a;
	list_b = b;
	i = 0;
	while (list_a || list_b)
	{
		// Print 'a' list with correct spacing for index
		if (list_a)
		{
			// Handle spacing based on index size
			if (i < 10)
				ft_printf("a  [%d]: %d", i, list_a->num);
			else if (i < 100)
				ft_printf("a [%d]: %d", i, list_a->num);
			else
				ft_printf("a[%d]: %d", i, list_a->num);

			// Handle spacing based on the number size
			if (list_a->num < 10)
				ft_printf("   ");  // 3 spaces after single digit
			else if (list_a->num < 100)
				ft_printf("  ");   // 2 spaces after two digits
			else if (list_a->num < 1000)
				ft_printf(" ");    // 1 space after three digits

			list_a = list_a->next;
		}

		// Print 'b' list with correct formatting (if list_b is not NULL)
		if (list_b)
		{
			if (i < 10)
				ft_printf("-----  b  [%d]: %d", i, list_b->num);
			else if (i < 100)
				ft_printf("-----  b [%d]: %d", i, list_b->num);
			else
				ft_printf("-----  b[%d]: %d", i, list_b->num);

			list_b = list_b->next;
		}

		ft_putchar_fd('\n', 1);
		i++;
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
