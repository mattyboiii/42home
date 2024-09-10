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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;
	
	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
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
