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

int main(int arc, char **arv)
{
	s_node *a;
	// s_node *b;

	if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else if (arc < 3)
		ft_exit(3);
	a = fill_a(arv);
	ft_printf("first num %d", a->num);
}
