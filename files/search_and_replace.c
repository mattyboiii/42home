#include <unistd.h>
#include <stdlib.h>

void	pc(char c)
{
	write(1, &c, 1);
}

int	main(int arc, char *arv[])
{
	if (arc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		char	repc;
		char	newc;
		int	i;
		
		i = 0;
		newc = arv[3][0];
		repc = arv[2][0];
		if (arv[2][1] || arv[3][1])
			arv[1][i] = 0;
		while (arv[1][i])
		{
			if (arv[1][i] == repc)
				pc(newc);
			else
				pc(arv[1][i]);
			i++;
		}
		write(1, "\n", 1);
	}
}
