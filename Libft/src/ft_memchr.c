
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	snap;
	size_t	i;

	ptr = (unsigned char *)s;
	snap = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		if (ptr[i] == snap)
			return((void *)&ptr[i]);
		i++;
	}
	return(NULL);
}
