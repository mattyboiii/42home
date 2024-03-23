/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:30:54 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 16:32:46 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: ft_strtrim
 ** --------------------------
 ** Prototype: char *ft_strtrim(char const *s1, char const *set);
 **
 ** Parameters:
 **    s1: The string to be trimmed.
 **    set: The reference set of characters to trim.
 **
 ** Return value:
 **    The trimmed string.
 **    NULL if the allocation fails.
 **
 ** External functions: malloc
 **
 ** Description:
 **    Allocates (with malloc(3)) and returns a copy of 's1' with the characters
 **    specified in 'set' removed from the beginning and the end of the string.
 */

#include "libft.h"

static char *retemptys()
{
	char	*str;
	str = malloc(1);
	if (str == NULL)
		return NULL;
	*str = '\0';
	return str;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (!s1)
		return (retemptys());

	str = malloc((ft_strlen(s1) - (start + end)) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, ft_strlen(str));
	return (str);
}
