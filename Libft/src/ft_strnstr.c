/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:40:04 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 10:50:40 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*ndl;

	hay = (char *)haystack;
	ndl = (char *)needle;
	i = 0;
	j = 0;
	if (!needle[0])
		return (hay);
	while (hay[i] && i < len)
	{
		while (hay[i + j] == ndl[j] && hay[i + j] && ndl[j] && i + j < len)
		{
			j++;
			if (!ndl[j])
				return (&hay[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
