/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logicfunk2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-29 23:59:11 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-29 23:59:11 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_number(t_node *lst)
{
	int		chunk_step;
	t_node	*big;
	t_node	*small;

	set_big_small(lst, &big, &small);
	if (ft_lstlast(lst)->pos <= 99)
		chunk_step = ((big->num - small->num) / 5);
	if (ft_lstlast(lst)->pos > 99)
		chunk_step = ((big->num - small->num) / 11);
	return (chunk_step);
}
