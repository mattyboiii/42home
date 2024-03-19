/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:27:59 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/19 20:00:59 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns the total length that the resulting string would have been if no truncation had occurred, regardless of whether the concatenation actually took place.

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	if (src == NULL)
		return strlen(dest);
	i = 0;
	j = 0;
	while (dest[i] && i < destsize)
		i++;
	while (src[j] && (i + j + 1) < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (i < destsize)
		return (i + strlen(src));
	else
		return (destsize + strlen(src));
}

