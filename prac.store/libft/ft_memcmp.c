/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:03:14 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 10:39:03 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//     The memcmp() function compares byte string s1 against byte string s2.
//     Both strings are assumed to be n bytes
//
// RETURN VALUES
//     The memcmp() function returns zero if the two strings are identical,
//     otherwise returns the difference between the first two differing bytes
//     (treated as unsigned char values, so that `\200' is greater than `\0',
//     for example). Zero-length strings are always identical.  This behavior
//     is not required by C and portable code should only depend on the sign
//     of the returned value.

//can return negative numbers

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	unsigned char		*p2;
	size_t				i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
