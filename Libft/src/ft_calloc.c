/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:47:40 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/21 16:37:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//      The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
//      allocate memory. The allocated memory is aligned such that it can be
//      used for any data type, including AltiVec- and SSE-related types. The
//      aligned_alloc() function allocates memory with the requested alignment.
//      The free() function frees allocations that were created via the
//      preceding allocation functions.
//
//      The malloc() function allocates size bytes of memory and returns a
//      pointer to the allocated memory.
//
//      The calloc() function contiguously allocates enough space for count
//      objects that are size bytes of memory each and returns a pointer to
//      the allocated memory. The allocated memory is filled with bytes of
//      value zero.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t		tsize;

	tsize = count * size;
	out = malloc(tsize);
	if (out == NULL)
		return (NULL);

	ft_memset(out, 0, tsize);
	return (out);
}
