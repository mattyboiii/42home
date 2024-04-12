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

char	*ft_strcatmal(char *dest, const char *src, char *address)
{
	char	*start;
	int	len;
	int	src_len;
	
	src_len = ft_strlen(src);
	while (!src_len && src[src_len - 1] == '\n')
		src_len--;
	len = ft_strlen(dest) + src_len + 1;
	address = malloc(sizeof(char) * len);
	start = address;
	while (*dest)
		*address++ = *dest++;
	while (*src && src_len-- > 0)
		*address++ = *src++;
	*address = '\0';
	return (start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
	{
		out = malloc(1);
		if (out)
			*out = '\0';
		return out;
	}
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;

	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	while (*s && i < len && start < ft_strlen(s))
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}

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
	while (*lst && (*lst)->next != NULL)
		*lst = (*lst)->next;
	if (!*lst)
		return (0);
	(*lst)->next = new;
	*lst = head;
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
