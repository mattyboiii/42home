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

size_t	ft_strlen(const char *s)
{
	unsigned char	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char		*dup;
	int		i;
	int		len;

	len = ft_strlen(src);
	dup = malloc(sizeof(char) * len + 1);
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (*src)
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		if (!lst || !del)
			return ;
		del((*lst)->buffer);
		free(lst);
		*lst = node;
	}
	*lst = NULL;
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*last;

	if (!lst || !new)
		return (0);
	if (*lst == NULL)
	{
		*lst = new;
		return (1);
	}
	while (*lst && (*lst)->next != NULL)
		*lst = (*lst)->next;

	last = *lst;
	if (!last)
		return (0);
	last->next = new;
	return (1);
}


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

void	delete_content(void *content)
{
    if (content)
        free(content);
}
