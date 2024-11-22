/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:56:54 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/29 12:31:37 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// unlike the other chunk size this one checks the entire lst
int	chunk_size_f(t_node *lst, int chunk)
{
	int		i;

	if (lst == NULL)
		return (0);
	if (lst->chunk != chunk)
		return (0);
	i = 0;
	if (lst->next == NULL)
		return (1);
	while (lst)
	{
		if (lst->chunk == chunk)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	main(int arc, char **arv)
{
	t_stacks stack;

	stack.a = NULL;
	stack.b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	error_check_arv(arv);
	fill_a(&stack, arv);
	// print_lstnums(stack.a, stack.b);
	// print_lstnums(stack.a, stack.b);
	if (sorted_asc(stack.a, stack.a, 0) == 1)
		exit (100);
	else if (chunk_size(stack.a, 0) <= 3)
		sort3(&stack.a);
	else if (chunk_size(stack.a, 0) <= 5)
		sort5(stack);
	else
		sort_to_b(stack);
	ft_lstclear(&stack.a);
	ft_lstclear(&stack.b);
	exit(600);
}
