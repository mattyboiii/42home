/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:08:48 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/23 13:50:58 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_strmapi
** --------------------------
** Prototype: char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
**
** Parameters:
**    s: The string on which to iterate.
**    f: The function to apply to each character.
**
** Return value:
**    The string created from the successive applications of 'f'.
**    NULL if the allocation fails.
**
** External functions: malloc
**
** Description:
**    Applies the function 'f' to each character of the string 's', passing its
**    index as the first argument to create a new string (with malloc(3))
**    resulting from successive applications of 'f'.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	//get string length of s
	char	*str;
	size_t	strlen;
	size_t	i;
	
	strlen = ft_strlen(s);
	str = malloc((sizeof(char) * strlen) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[strlen] = '\0';
	return (str);
}
