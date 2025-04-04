/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ischar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:57:16 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/04 11:57:24 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ischar(char *str, size_t start, char c)
{
	size_t	i;

	i = start;
	if (ft_strlen(str) <= start)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
