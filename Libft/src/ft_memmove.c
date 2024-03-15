#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*temp;
	size_t	i;

	ptr = (char *)src;
	i = 0;
	temp = malloc(n * sizeof(char));
	if (temp == NULL)
		return(NULL);
	while(i < n)
	{
		temp[i] = ptr[i];
		i++;
	}
	i = 0;
	while(i < n)
	{
		((char *)dest)[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
