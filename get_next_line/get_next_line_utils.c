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

int	ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == ch)
			return (1);
		ptr++;
	}
	if (ch == '\0')
		return (0);
	else
		return (0);
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

t_list	*update_list_buffer(t_list *lst, t_list *new)
{
	char	*start;
	char	*ptr;
	size_t	len;
	size_t	i;
	
	i = 0;
	len = ft_strlen(lst->buffer) + ft_strlen(new->buffer) + 1;
	start = malloc(sizeof(char) * len);
	ptr = start;
	while (i < ft_strlen(lst->buffer))
		*ptr++ = lst->buffer[i++];
	i = 0;
	while (i < ft_strlen(new->buffer))
		*ptr++ = new->buffer[i++];
	*ptr = '\0';

	free(lst->buffer);
	free(new->buffer);
	lst->buffer = start;
	return (lst);
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
	if (!(*lst))
		return (0);
	if ((*lst)->buffer[ft_strlen((*lst)->buffer) - 1] == '\n')
	{
		(*lst)->next = new;
		*lst = head;
		return (1);
	}
	else
	{
		*lst = update_list_buffer(*lst, new); 
		*lst = head;
		return (1);
	}
}

