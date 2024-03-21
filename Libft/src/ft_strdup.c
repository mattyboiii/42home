/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:06:15 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/21 15:43:52 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//    The strdup() function allocates sufficient memory for a copy of the string
//    s1, does the copy, and returns a pointer to it. The pointer may subsequently
//    be used as an argument to the function free(3).
//
//    If insufficient memory is available, NULL is returned and errno is set to
//    ENOMEM.
//
//    The strndup() function copies at most n characters from the string s1 always
//    NUL terminating the copied string.

// FOR ME - i used the [i] to keep track of the start of the dup pointer to ensure
// the correct return value. 

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * len + 1);
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (*src)
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}
