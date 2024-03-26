#include "libft.h"

void	*p_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*temp;
	size_t	i;

	ptr = (char *)src;
	temp = malloc((sizeof(char)) * n);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp[i] = ptr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = temp[i];
		i++;
	}
	free(temp);
	return(dest);
}
