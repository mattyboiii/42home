/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:23:58 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 16:36:20 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_substr
 ** -------------------------
 ** Prototype: char *ft_substr(char const *s, unsigned int start, size_t len);
 **
 ** Parameters:
 **    s: The string from which to create the substring.
 **    start: The start index of the substring in the string 's'.
 **    len: The maximum length of the substring.
 **
 ** Return value:
 **    The substring.
 **    NULL if the allocation fails.
 **
 ** External functions: malloc
 **
 ** Description:
 **    Allocates (with malloc(3)) and returns a substring from the string 's'.
 **    The substring begins at index 'start' and is of maximum size 'len'.
 */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	out = malloc((sizeof(char)) * (len + 1));
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
