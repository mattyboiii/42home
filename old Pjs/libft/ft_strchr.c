/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:18:25 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 14:52:51 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//DESCRIPTION
//    The strchr() function locates the first occurrence of c (converted to
//    a char) in the string pointed to by s.  The terminating null character is
//    considered to be part of the string; therefore if c is `\0', the 
//    functions locate the terminating `\0'.

//RETURN VALUES
//     The functions strchr() and strrchr() return a pointer to the located
//     character, or NULL if the character does not appear in the string.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	if (ch == '\0')
		return (ptr);
	else
		return (NULL);
}
