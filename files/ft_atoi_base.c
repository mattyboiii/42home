#include <stdio.h>


// res = res * str_base + vo(*str++)

int	isdig(char c, int str_base)
{
	const char	digs[17] = "0123456789abcdef";
	const char	digs1[17] = "0123456789ABCDEF";

	while (str_base--)
	{
		if (c == digs[str_base] || c == digs1[str_base])
			return (1);
	}
	return (0);
}

int	vo(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	if (*str == '0')
		return (0);
	while (isdig(*str, str_base))
		res = res * str_base + vo(*str++);
	return (res * sign);
}
/*
int	main(void)
{
	char *num;
	int	n1;
	char *numn;
	int	nn;

	num = "42";
	n1 = ft_atoi_base(num, 8);
	printf("res: %d\n", n1);
	numn = "-42";
	nn = ft_atoi_base(numn, 8);
	printf("-res: %d\n", nn);
	

}
*/
