#include <string.h>
#include <stdio.h>

int	rej_func(char c, char *str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	size_t	bytes;
	char	*str;
	char	*rej;

	if (s == NULL || *s == '\0')
		return (0);
	str = (char *)s;
	rej = (char *)reject;

	bytes = 0;
	i = 0;
	while (rej_func(str[i++], rej) == 0)
		bytes++;
	return (bytes);
}
/*
int	main(int arc, char *arv[])
{
	int	num;
	int	num2;

	if (arc == 3)
	{
		const char *str = arv[1];
		const char *rej = arv[2];

		num = ft_strcspn(str, rej);
		num2 = strcspn(str, rej);
		printf("myfunc : %d\n", num);
		printf("strcspn: %d\n", num2);
	}
	return (0);
}
*/
