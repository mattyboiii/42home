#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



void	pc(char c)
{
	write(1, &c, 1);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}
int	check_string(char *str)
{
	int	loop;

	loop = 0;
	while (*str)
	{
		while (*str && ft_space(*str) == 1)
			str++;
		if (*str && ft_space(*str) == 0 && loop)
			return (1);
		while (*str && ft_space(*str) == 0)
			str++;
		loop++;
	}
	return (0);
}

void	rostring(char *str)
{
	int		i;
	int		len;
	char		*first;
	char		*headfirst;
	

	i = 0;
	len = 0;
	if (!check_string(str))
	{
		while (*str && ft_space(*str) == 1)
			str++;
		while (*str && ft_space(*str) == 0)
			pc(*str++);
		pc('\n');
		return ;
	}
	else
	{
		while (*str && ft_space(str[i]) == 1)
			i++;
		while (*str && ft_space(str[i]) == 0)
		{
			len++;
			i++;
		}
		first = malloc(sizeof(char) * len + 1);
		if (first == NULL)
			return ;
		first[len] = '\0';
		headfirst = first;
		while (*str && ft_space(*str) == 0)
			*first++ = *str++;
		while(*str)
		{
			while(*str && ft_space(*str) == 1)
				str++;
			while (*str && ft_space(*str) == 0)
				pc(*str++);
			if (*str && ft_space(*str) == 1)
				pc(*str++);
		}
		pc(' ');
		first = headfirst;
		while (*first)
			pc(*first++);
		free(headfirst);
		pc('\n');
	}
}

int	main(int arc, char *arv[])
{
	if (arc >= 2)
	{
		if (arv[1] == 0)
			pc('\n');
		else
			rostring(arv[1]);
	}
	else
		pc('\n');
	return (0);
}
