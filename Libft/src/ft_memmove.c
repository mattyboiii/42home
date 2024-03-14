#include "libft.h"

void *memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*temp;
	int	i;

	ptr = *src;
	i = 0;
	while(i < n)
	{
		temp[i] = ptr[i];
		i++;
	}
	i = 0;
	while(i < n)
	{
		dest[i] = temp[i];
		i++;
	}
	return (dest);
}
