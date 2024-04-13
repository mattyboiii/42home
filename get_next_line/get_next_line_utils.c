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

void	ft_strcatmal(char *dest, const char *src, char **address)
{
	char	*start;
	int	len;

	len = ft_strlen(dest) + ft_strlen(src) + 1;
	*address = malloc(sizeof(char) * len);
	start = *address;
	while (*dest)
		*(*address)++ = *dest++;
	while (*src)
		*(*address)++ = *src++;
	*(*address) = '\0';
	*address = start;
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

