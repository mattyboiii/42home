/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:47:06 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:49 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_strjoin
 ** --------------------------
 ** Prototype: char *ft_strjoin(char const *s1, char const *s2);
 **
 ** Parameters:
 **    s1: The prefix string.
 **    s2: The suffix string.
 **
 ** Return value:
 **    The new string.
 **    NULL if the allocation fails.
 **
 ** External functions: malloc
 **
 ** Description:
 **    Allocates (with malloc(3)) and returns a new string, which is the result
 **    of the concatenation of 's1' and 's2'.
 */

#include "libft.h"

static char	*retemptys(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;
	size_t	s1l;
	size_t	s2l;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (s1l == 0 && s2l == 0)
		return (retemptys());
	str = malloc ((s1l + s2l) + 1);
	start = str;
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}
