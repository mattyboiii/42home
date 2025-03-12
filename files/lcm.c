#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int		i;
	unsigned int	lca;
	unsigned int	lcb;
	unsigned int	max;

	max = a * b;
	i = 0;
	lca = 0;
	lcb = 0;
	while (lca <= max || lcb <= max)
	{
		i++;
		if (lca < max)
			lca = a * i;
		if (lcb < max)
			lcb = b * i;
		if (lca == lcb)
			return (lca);
	}
	return (0);
}
/*
int	main(int arc, char *arv[])
{
	if (arc == 3)
	{
		unsigned int	num1;
		unsigned int	num2;
		unsigned int res;

		num1 = atoi(arv[1]);
		num2 = atoi(arv[2]);
		res = lcm(num1, num2);
		printf("lcm: %d\n", res);
	}
	else
		printf("arc != 3\n");
	return (0);
}
*/
