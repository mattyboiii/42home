#include <stdlib.h>
#include <unistd.h>

//42 / 2 = 21 (add 2) 2 / 21 isnt diviasble. 
// move onto 21 / 3 = 7. add 3. 

int	isp(int num)
{
	int	div;

	if (num < 2)
		return (0);
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

void	printnum(int num)
{
	if (num >= 10)
		printnum(num / 10);
	pc((num % 10) + '0');
}

void	fprime(char *str)
{
	int		num;
	int		div;
	int		first;

	first = 1;
	div = 1;
	num = atoi(str);
	if (num == 1)
		pc('1');
	while (num > div)
	{
		while (isp(div) == 0)
			div++;
		while (num % div == 0)
		{
			if (first)
				first = 0;
			else
				pc('*');
			printnum(div);
			num /= div;
		}
		div++;
	}
}

int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		fprime(arv[1]);
	}
	pc('\n');
}
