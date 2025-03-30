/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwong <clwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:17 by clwong            #+#    #+#             */
/*   Updated: 2025/03/10 12:32:25 by clwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int		i;
	ssize_t	bytes_written;

	i = 0;
	while (str[i] != '\0')
	{
		bytes_written = write(1, &str[i], 1);
		(void)bytes_written;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	find_min(t_stack_node *head)
{
	t_stack_node	*temp;
	int				minimum;

	temp = head->next;
	minimum = head->data;
	if (!head)
		return (INT_MAX);
	while (temp)
	{
		if (temp->data < minimum)
			minimum = temp->data;
		temp = temp->next;
	}
	return (minimum);
}

int	find_max(t_stack_node *head)
{
	int				maximum;
	t_stack_node	*temp;

	maximum = head->data;
	temp = head->next;
	if (!head)
		return (INT_MIN);
	while (temp)
	{
		if (temp->data > maximum)
			maximum = temp->data;
		temp = temp->next;
	}
	return (maximum);
}
