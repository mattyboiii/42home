/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:10:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/25 14:47:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_split
** ------------------------
** Prototype: char **ft_split(char const *s, char c);
**
** Parameters:
**    s: The string to be split.
**    c: The delimiter character.
**
** Return value:
**    The array of new strings resulting from the split.
**    NULL if the allocation fails.
**
** External functions: malloc, free
**
** Description:
**    Allocates (with malloc(3)) and returns an array of strings obtained by
**    splitting 's' using the character 'c' as a delimiter. The array must end
**    with a NULL pointer.
*/
// FOR ME
//    if the string is "  one       two      three  " and c = " " ft_split
//    needs to return an array containing out[0] = "one" out[1] = "two"
//    out[2] = "three" out[3] = '\0'

#include "libft.h"

char	*ft_stpcpy(char * dst, const char * src)
{

}

char	**strins(char **dst, char *str)
{
	int		i;
	char	**new_arr;

	i = 0;
	while (dst[i] != NULL)
		i++;
	new_arr = malloc((sizeof(char *) * ft_strlen(str)));
	
	dst[i] = ft_strdup(str);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*trim;
	char	*str;
	// int		strlen;
	int		i;
	
	i = 0;
	out = NULL;
	trim = ft_strtrim(s, &c); // "one       two      three"
	while (trim[i] != '\0' && trim[i] != c)
		i++;
	str = ft_substr(str, 0, ft_strlen(str));
	out = strins(out, str);

	// strlen = ft_strlen(s);
	return (NULL);
}
