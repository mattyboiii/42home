/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:44:18 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/20 19:09:44 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//     The strchr() function locates the first occurrence of c
//     (converted to a char) in the string pointed to by s.  The terminating 
//     null character is considered to be part of the string; therefore if c 
//     is `\0', the functions locate the terminating `\0'.

//     The strrchr() function is identical to strchr(), except it locates the last occurrence of c.

//RETURN VALUES
//     The functions strchr() and strrchr() return a pointer to the located 
//     character, or NULL if the character does not appear in the string.

#include "libft.h"

char *strrchr(const char *s, int c)
{
	char		*ptr;
	size_t		i;
	char		ch;

	ch = (char)c;
	ptr = (char *)s;
	i = ft_strlen(ptr);
	while (ptr[i] != '\0' && ptr[i] != ch)
		i--;
	if (ptr[i] == ch)
		return (&ptr[i]);
	else
		return (NULL);
}
