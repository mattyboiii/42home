/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:57:07 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/22 10:57:47 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	snap;
	size_t			i;

	ptr = (unsigned char *)s;
	snap = (unsigned char)c;
	if (n == 0)
		return (NULL);
	i = n - 1;
	while (i > 0)
	{
		if (ptr[i] == snap)
			return ((void *)&ptr[i]);
		i--;
	}
	if (ptr[0] == snap)
		return ((void *)&ptr[0]);
	return (NULL);
}
