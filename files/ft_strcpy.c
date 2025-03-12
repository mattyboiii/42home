#include <stddef.h>

char *ft_strcpy(char *s1, char *s2)
{
	char	*head;
	head = s1;
	if (s2 == NULL)
		return (NULL);
	while (s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1);
}
