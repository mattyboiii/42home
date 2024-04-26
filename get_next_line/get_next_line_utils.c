/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:11:23 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/24 14:57:49 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isnewl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_list	*string_into_linkedlist(t_list **lst, char *str)
{
	t_list	*node;
	t_list	*head;

	head = *lst;
	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->buffer = str;
	node->next = NULL;
	if (!*lst)
		return (*lst = node);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = node;
	*lst = head;
	return (head);
}

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{

	if (!*lst || !del)
		return ;
	del((*lst)->buffer);
	(*lst)->buffer = NULL;
	free(*lst);
	*lst = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}
