#include <unistd.h>



int	ip(int num)
{
	int	div;

	div = 2;
	while (div < num)
	{
		if (num % div == 0)
			return (0);
		div++;
	}
	return (1);
}


void	pc(char c)
{
	write(1, &c, 1);
}
int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void	printnum(int num)
{
	if (num >= 10)
		printnum(num / 10);
	pc((num % 10) + '0');
}

void	add_prime_sum(int num)
{
	int	res;
	int	i;
	
	if (num < 2)
		pc('0');
	else
	{
		i = 2;
		res = 0;
		while (i <= num)
		{
			if (ip(i) == 1)
				res += i;
			i++;
		}
		printnum(res);
	}
	
}

int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		int	num;

		num = ft_atoi(arv[1]);
		if (num == 0)
			pc('0');
		else
			add_prime_sum(num);
		pc('\n');
	}
	else
	{
		pc('0');
		pc('\n');
	}
}
