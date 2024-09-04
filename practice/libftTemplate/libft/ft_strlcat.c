/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:27:59 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/20 11:38:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  
    Description

     The strlcpy() and strlcat() functions copy and concatenate strings
     respectively. They are designed to be safer, more consistent, and
     less error prone replacements for strncpy(3) and strncat(3). Unlike
     those functions, strlcpy() and strlcat() take the full size of the
     buffer (not just the length) and guarantee to NUL-terminate the
     result (as long as size is larger than 0 or, in the case of
     strlcat(), as long as there is at least one byte free in dst).
     Note that a byte for the NUL should be included in size. Also note
     that strlcpy() and strlcat() only operate on true ''C'' strings.
     This means that for strlcpy() src must be NUL-terminated and for
     strlcat() both src and dst must be NUL-terminated.

     The strlcat() function appends the NUL-terminated string src to the
     end of dst. It will append at most size - strlen(dst) - 1 bytes,
     NUL-terminating the result.

    Return Values

     The strlcpy() and strlcat() functions return the total length of
     the string they tried to create. For strlcpy() that means the
     length of src. For strlcat() that means the initial length of dst
     plus the length of src. While this may seem somewhat confusing,
     it was done to make truncation detection simple.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (destsize + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && (i + j + 1) < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest_len + src_len);
}
