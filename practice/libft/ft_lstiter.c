/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:03:51 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/31 12:12:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_lstiter
** --------------------------
** Prototype: void ft_lstiter(t_list *lst, void (*f)(void *));
**
** Parameters:
**    lst: The address of a pointer to a node.
**    f: The address of the function used to iterate on the list.
**
** Return value: None
**
** External functions: None
**
** Description:
**    Iterates the list 'lst' and applies the function 'f' on the content of
**    each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
