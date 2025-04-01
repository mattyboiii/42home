/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:07:02 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/12 18:20:16 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** DESCRIPTION
 **
 **    The strstr() function finds the first occurrence of the substring
 **    needle in the string haystack. The terminating null bytes ('\0') are not
 **    compared.
 **
 **    The strcasestr() function is like strstr(), but ignores the case of
 **    both arguments.
 **
 ** RETURN VALUE
 **
 **    These functions return a pointer to the beginning of the located
 **    substring, or NULL if the substring is not found.
 **
 **    If needle is the empty string, the return value is always haystack
 **    itself.
 */

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*ndl;

	hay = (char *)haystack;
	ndl = (char *)needle;
	i = 0;
	j = 0;
	if (!needle[0])
		return (hay);
	while (hay[i])
	{
		while (ndl[j] && hay[i + j] == ndl[j])
		{
			j++;
			if (!ndl[j])
				return (&hay[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
