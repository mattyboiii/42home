#include <stdio.h>
#include <stdlib.h>


int	isdig(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return(0);
}

int	isal(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
int	check_str(const char *str)
{
	int	i;

	i = 0;
	while (isdig(str[i]) != 1)
	{
		if (str[i] == '\0')
			return(0);
		if (str[i] == '-' && isdig(str[i + 1]) == 0)
			return (0);
		if (str[i] == '+' && isdig(str[i + 1]) == 0)
			return (0);
		if (isal(str[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;


	sign = 1;
	res = 0;
	if (check_str(str) == 0)
		return (0);
	while (isdig(*str) == 0)
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return(res * sign);
}
/*
int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		int	num1;
		int	num2;

		num1 = ft_atoi(arv[1]);
		num2 = atoi(arv[1]);

		printf("myfunc: %d\n", num1);
		printf("pcfunc: %d\n", num2);
	}
}
*/
