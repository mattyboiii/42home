/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 06:25:41 by mtripodi          #+#    #+#             */
/*   Updated: 2025-02-10 06:25:41 by mtripodi         ###   ########:w        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief this functions is strcat, but it catonates the str given to every
 * string inside of the dp array.
 *
 * @return a double pointer array with str on the end
 */
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
		if (dp_strcat[i] == NULL)
		{
			dp_free(&dp_strcat);
			return (NULL);
		}
		i++;
	}
	dp_strcat[i] = NULL;
	dp_free(&paths);
	return (dp_strcat);
}
