/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexuCharlie <charlie_xumeng@hotmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:26:57 by charlie           #+#    #+#             */
/*   Updated: 2024/10/28 12:38:25 by mexuCharlie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

#include "libft.h"

// return a substring from the string s, begins at index start and length is len
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	size_t	str_len;
	size_t	idx;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len + start > str_len)
		substr_len = str_len - start;
	else
		substr_len = len;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	idx = 0;
	while (idx < substr_len)
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[substr_len] = '\0';
	return (substr);
}
