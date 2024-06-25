/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:46:02 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/28 15:15:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstlast
** --------------------------
** Prototype: t_list *ft_lstlast(t_list *lst);
**
** Parameters:
**    lst: The beginning of the list.
**
** Return value:
**    Last node of the list.
**
** External functions: None
**
** Description:
**    Returns the last node of the list.
*/

// the below code works because the node after the last node == NULL.

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
