/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:33:35 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/26 16:46:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	snap;
	size_t			i;

	ptr = (unsigned char *)s;
	snap = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == snap)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
