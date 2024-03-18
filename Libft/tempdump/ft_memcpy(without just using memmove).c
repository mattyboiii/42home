#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)dest;
	i = 0;
	while(i < n && ptr[i] == '\0')
	{
		if (i < n)
			ft_memmove(dest, src, n);
		else
			ft_memmove(dest, src, n);
		i++;
	}
	return(dest);
}
