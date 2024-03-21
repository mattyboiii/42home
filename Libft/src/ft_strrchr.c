/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:44:18 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/21 14:29:57 by mtripodi         ###   ########.fr       */
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

char *ft_strrchr(const char *s, int c)
{
    char	*ptr;
    char	ch; 
	
	ch = (char)c;
    ptr = (char *)s + ft_strlen(s);

    while (ptr >= s) 
	{
        if (*ptr == ch)
            return (ptr);
        ptr--;
	}
    return (NULL);
}

