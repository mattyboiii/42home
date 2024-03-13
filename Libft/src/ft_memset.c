#include "libft.h"

void	ft_memset(void *s, int c, size_t len)
{
	unsigned char *ptr;
	unsigned int i;

	ptr = s;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
