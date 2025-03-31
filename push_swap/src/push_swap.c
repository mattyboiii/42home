/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/06 12:42:34 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	sorted_asc(t_node *lst, t_node *start)
{
	t_node	*head;

	head = lst;
	while (lst != start)
		lst = lst->next;
	while (lst->next != NULL)
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

void	ft_exit(int n)
{
	if (n == 0)
		exit(0);
	if (n == 6)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
}

int	main(int arc, char **arv)
{
	t_stacks	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	error_check_arv(arv);
	fill_a(&stack, arv);
	stack.bigdig = set_bigdig(&stack);
	if (stack.asize <= 1)
		exit(0);
	if (sorted_asc(stack.a, stack.a) == 1)
		return (0);
	else if (stack.asize <= 3)
		sort3(&stack.a);
	else
		sort(&stack);
	ft_lstclear(&stack.a);
	ft_lstclear(&stack.b);
	return (0);
}
