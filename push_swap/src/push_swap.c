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

int	sizeofa(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	main(int arc, char **arv)
{
	t_node	*a;
	t_node	*b;
	int		*numa;


	a = NULL;
	b = NULL;
	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	error_check_arv(arv);
	a = fill_a(arv);
	numa = node_to_array(a);
	numa = quicksort(numa, sizeofa(numa), 0);
	ft_printf("numa %d", numa);
	ft_printf("first num %d", a->num);
	b = ft_lstnew(1, 0, 'b');
	ft_printf("first num %d", b->num);
	sort3(a);
}
// the next thing you need to do is ad rra and rrb. This will probably need
// lst del functions, because you are moving them from a to b now.
