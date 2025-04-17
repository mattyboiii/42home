/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   natefunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 01:06:53 by mtripodi          #+#    #+#             */
/*   Updated: 2025-04-09 01:06:53 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnjoin(unsigned int num_strs, ...)
{
	va_list	args;
	char	*out;
	char	**strs;
	size_t	i[3];

	va_start(args, num_strs);
	strs = malloc(num_strs * sizeof(char *));
	i[2] = 0;
	i[0] = 0;
	while (i[2] < num_strs)
	{
		strs[i[2]] = va_arg(args, char *);
		i[0] += ft_strlen(strs[i[2]]);
		++i[2];
	}
	out = malloc((i[0] + 1) * sizeof(char));
	out[0] = 0;
	i[2] = 0;
	i[1] = 0;
	while (i[2] < num_strs && i[1] < i[0])
		i[1] += ft_strlcpy(out + i[1], strs[i[2]++], i[0] + 1 - i[1]);
	free(strs);
	va_end(args);
	return (out);
}
