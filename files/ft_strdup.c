#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
char *ft_strdup(char *src)
{
	int	len;
	char	*dup;
	char	*head;

	if (src == NULL || *src == '\0')
	{
		dup = malloc(1);
		dup[0] = '\0';
		return (dup);
	}
	len = ft_strlen(src);
	dup = malloc(sizeof(char) * len + 1);
	head = dup;
	if (dup == NULL)
		return (NULL);
	while (*src)
		*dup++ = *src++;
	*dup = 0;
	return (head);
}

/*
int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		char	*str1;
		char	*str;

		str1 = strdup(arv[1]);
		str = ft_strdup(arv[1]);
		printf("str1: %s\n", str1);
		printf("str : %s\n", str);
	}
}
*/
