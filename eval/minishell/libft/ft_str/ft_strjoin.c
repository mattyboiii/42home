/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:27:19 by charlie           #+#    #+#             */
/*   Updated: 2024/11/07 10:01:04 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	char	*p;

	str_joined = (char *)malloc(sizeof(char)
			*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str_joined == NULL)
		return (NULL);
	p = str_joined;
	while (*s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	return (str_joined);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*str_joined;
	char	*p;

	str_joined = (char *)malloc(sizeof(char)
			*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str_joined == NULL)
		return (NULL);
	p = str_joined;
	while (*s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	return (ft_free(s1), ft_free(s2), str_joined);
}
