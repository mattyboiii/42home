/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:07 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 16:31:38 by mtripodi         ###   ########.fr       */
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

static int	get_wordcount(char *str, char c)
{
	int		i;
	int		wordc;

	i = 0;
	wordc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wordc++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wordc);
}

static int	get_wordlen(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*full_word(char *str, char c)
{
	char	*word;
	int		wordlen;
	int		i;

	i = 0;
	wordlen = get_wordlen(str, c);
	word = malloc((sizeof(char) * (wordlen + 1)));
	if (word == NULL)
		return (NULL);
	while (i < wordlen)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	out = malloc((sizeof(char *) * (get_wordcount(str, c) + 1)));
	if (out == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			out[i] = full_word(str, c);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	out[i] = 0;
	return (out);
}
