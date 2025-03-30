/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:57 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:30:21 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief order_check checs the order of the list. The funciton first
 * turns the list into a circle, so that it will loop forever unless a
 * condition is met. It will start at the number following the biggest.
 * if the number is smaller, it will keep going, if not. it will return
 * 0
 *
 * if it loops completely, by hitting the biggest number again, it will
 * exit, cut the circle then return 1
 *
 * @return returns 1 or 0. 1 meaning it is successfully in order
 */
int	order_check(t_node **lst)
{
	int		cut;
	t_node	*big;
	t_node	*compare;

	if (ft_lstsize(*lst) <= 2)
		return (1);
	set_big_small(*lst, &big, 0);
	cut = make_circle(lst);
	compare = big->next;
	while (compare != big)
	{
		if (compare->num > compare->prev->num)
		{
			cut_circle(lst, cut);
			return (0);
		}
		compare = compare->next;
	}
	cut_circle(lst, cut);
	return (1);
}

