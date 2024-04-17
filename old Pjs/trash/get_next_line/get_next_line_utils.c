/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:11:23 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/04 11:11:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->buffer = content;
	node->next = NULL;
	return (node);
}
*/
void	clean_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}

size_t	ft_strlen(const char *s)
{
	unsigned char	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	str = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	start = str;
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*head;

	if (!lst || !new)
		return (0);
	head = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		head = *lst;
		return (1);
	}
	while (*lst && *lst != NULL && (*lst)->next != NULL)
		*lst = (*lst)->next;
	if (!(*lst))
		return (0);
	(*lst)->next = new;
	*lst = head;
	return (1);
}
