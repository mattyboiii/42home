/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:18:24 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/19 15:45:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// practicing ft split 

#include <stdlib.h>

int		wordc(char *str, char c)
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

char	*get_word(char *str, char c)
{
	char	*word;
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (str[l] && str[l] != c)
		l++;
	word = malloc(sizeof(char) * (l + 1));
	if (word == NULL)
		return (NULL);
	while (i < l)
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
	out = malloc(sizeof(char *) * (wordc(str, c) + 1));
	if (out == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			out[i] = get_word(str, c);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	out[i] = 0;
	return (out);
}
