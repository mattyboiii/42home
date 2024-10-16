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

int	main(int arc, char **arv)
{
	t_node	*a;
	t_node	*b;
	t_node	**sort;
	int		*numa;

	a = NULL;
	b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	error_check_arv(arv);
	fill_a(&a, arv);
	print_lstnums(a);
	rrs(&a, 1);
	print_lstnums(a);
	if (ft_lstlast(a)->pos <= 2)
		sort3(&a);
	print_lstnums(a);
	a = get_head(a);
	print_lstnums(a);
	fill_a(sort, arv);
	print_lstnums(*sort);
	*sort = simple_sort(*sort);
	print_lstnums(*sort);
}
// the next thing you need to do is ad rra and rrb. This will probably need
// lst del functions, because you are moving them from a to b now.
