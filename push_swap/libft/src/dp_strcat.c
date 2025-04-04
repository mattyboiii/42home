/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:55:29 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/21 10:56:39 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// this function is just strcat, but it applies the str to every
// string in the dp array.
char	**dp_strcat(char **paths, char *str)
{
	int		i;
	char	**dp_strcat;

	i = 0;
	while (paths[i])
		i++;
	dp_strcat = malloc((sizeof(char *) * (i + 1)));
	if (dp_strcat == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		dp_strcat[i] = ft_strjoin(paths[i], str);
		i++;
	}
	dp_strcat[i] = NULL;
	dp_free(&paths);
	return (dp_strcat);
}
