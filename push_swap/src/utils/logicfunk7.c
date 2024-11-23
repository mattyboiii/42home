/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logicfunk7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 01:47:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024-11-17 01:47:50 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	posnum(int num)
{
	if (num < 0)
		return (num *= -1);
	else
		return (num);
}

int	negnum(int num)
{
	if (num > 0)
		return (num *= -1);
	else
		return (num);
}
