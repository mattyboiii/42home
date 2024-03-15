
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int	i;

	ptr=*s;
	i = 0;
	while(i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	return (s);
}
