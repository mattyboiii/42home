/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:18:25 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/19 11:11:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	size_t		i;

	ptr = s;
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != c)
		i++;
	if (ptr[i] == c)
		return ((char *)&ptr[i]);
	else
		return (NULL);
}
