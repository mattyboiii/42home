/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:09:36 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 10:49:56 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//     The strncmp() function compares two strings
//     data, characters that appear after a `\0' character are not compared.

// RETURN VALUES
//     The strcmp() and strncmp() functions return an integer greater 
//     than, equal to, or less than 0, according as the string s1 is 
//     greater than, equal to, or less than the string s2. The comparison 
//     is done using unsigned characters, so that `\200' is greater than `\0'.

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (*s1 && *s2)
	{
		if (p1[i] != p2[i] || !p1[i] || !p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
