/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexuCharlie <charlie_xumeng@hotmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:52:45 by charlie           #+#    #+#             */
/*   Updated: 2024/11/04 22:54:35 by mexuCharlie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	ft_free(lst);
}
