#include <stdlib.h>
#include <stdio.h>

int	ic(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (0);
	if (c >= 31 && c <= 126)
		return (1);
	return (0);
}

int	wordc(char *str)
{
	int	wordc;
	
	wordc = 0;
	while (*str)
	{
		while (ic(*str) == 0)
			str++;
		if (ic(*str) == 1)
			wordc++;
		while (ic(*str) == 1)
			str++;
	}
	return (wordc);
}

char	*getword(char *str)
{
	char	*s;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (ic(str[i++]) == 1)
		len++;
	s = malloc(sizeof(char) * len + 1);
	s[len] = '\0';
	i = 0;
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

char	**ft_split(char *str)
{
	int	i;
	char	*s;
	char	**out;

	if (*str == '\0')
		return (NULL);
	s = str;
	i = 0;
	out = malloc(sizeof(char *) * wordc(s) + 1);
	if (out == NULL)
		return (NULL);
	while (*s)
	{
		while (ic(*s) == 0)
			s++;
		if (ic(*s) == 1)
			out[i] = getword(s);
		while (ic(*s) == 1)
			s++;
		i++;
	}
	out[i] = '\0';
	return (out);
}
/*
int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		char	**str;
		int	i;

		str = ft_split(arv[1]);
		i = 0;
		while (str[i])
		{
			printf("str[%d]: %s\n", i, str[i]);
			i++;
		}
	}
	else
		printf("missing string");
	return (0);
}
*/
