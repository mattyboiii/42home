/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:56:57 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 14:03:55 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char	**instr(char **dst, char *str)
{
	
}
*/
char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*trim;
	//char	*str;
	int		i;
	
	i = 0;
	if (c == 'a')
		printf("c %c", c);
	out = malloc(sizeof(char *));
	if (out == NULL)
		return (NULL);
	out[0] = NULL;
	trim = (char *)s;
	return (NULL);
}
