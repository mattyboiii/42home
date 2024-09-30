/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:15:49 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/30 16:40:59 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*fill_a(char **arv)
{
	int		i;
	t_node	*lst;
	t_node	*node;

	i = 0;
	lst = NULL;
	while (arv[i])
	{
		if (arv[i][0] == '/')
		{
			i++;
			node = ft_lstnew(ft_atoi(arv[i]), i - 1);
		}
		else
			node = ft_lstnew(ft_atoi(arv[i]), i - 1);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

void	sa(t_node *node)
{
	int		swap;

	if (node == NULL || node->next == NULL)
		return ;
	swap = node->num;
	node->num = node->next->num;
	node->next->num = swap;
}

void	ra(t_node *node)
{
	int		swap;
	t_node	*last;

	if (node == NULL || node->next == NULL)
		return ;
	last = ft_lstlast(node);
	swap = node->num;
	node->num = last->num;
	last->num = swap;
}
