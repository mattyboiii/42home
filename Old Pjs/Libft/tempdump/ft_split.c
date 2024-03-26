/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:10:50 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 14:50:47 by mtripodi         ###   ########.fr       */
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
/*
   char	*ft_stpcpy(char * dst, const char * src)
   {

   }
   */

static char	**strins(char **dst, char *str)
{
	int		i;
	int		j;
	char	**new_arr;

	i = 0;
	j = 0;
	while (dst[i] != NULL)
		i++;
	new_arr = malloc((sizeof(char *) * (i + 2)));
	if (new_arr == NULL)
		return (NULL);

	if (i >= 1)
		while (j < i)
		{
			new_arr[j] = dst[j];
			j++;
		}
	new_arr[i] = ft_strdup(str);
	if (new_arr[i] == NULL)
	{
		free(new_arr);
		return (NULL);
	}
	new_arr[i + 1] = 0;
	free(dst);
	return (new_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*trim;
	char	*str;
	int		i;

	out = malloc((sizeof(char *)));
	if (out == NULL)
		return (NULL);
	out[0] = NULL;
	if (ft_strlen(s) == 0)
		return (out);
	trim = (char *)s;
	while (ft_strlen(trim) > 0)
	{
		i = 0;
		trim = ft_strtrim(trim, &c); // "one       two      three"
		while (trim[i] != '\0' && trim[i] != c)
			i++;
		str = ft_substr(trim, 0, i);
		if (ft_strlen(str) == 0)
		{
			free(str);
			free(trim);
			return (out);
		}
		trim = ft_substr(trim, i, ft_strlen(trim));
		out = strins(out, str);
	}
	free(str);
	free(trim);
	return (out);
}
