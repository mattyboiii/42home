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
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	error_check_arv(arv);
	fill_a(&a, arv);
	i = order_check(a, b, 0);
	if (sorted_asc(a, a, 0) == 1)
		exit (100);
	else if (chunk_size(a, 0) <= 3)
		sort3(&a);
	else if (chunk_size(a, 0) <= 5)
		sort5(&a, &b);
	else
		sort_to_b(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit(600);
}
