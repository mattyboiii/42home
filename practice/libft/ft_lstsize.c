/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:11:25 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/28 14:44:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstsize
** --------------------------
** Prototype: int ft_lstsize(t_list *lst);
**
** Parameters:
**    lst: The beginning of the list.
**
** Return value:
**    The length of the list.
**
** External functions: None
**
** Description:
**    Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
