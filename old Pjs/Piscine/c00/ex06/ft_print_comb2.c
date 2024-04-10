#include <stdio.h>
#include <unistd.h>


void printchar(char c)
{
	write(1, &c, 1);
}


void ft_print_comb(void)
{
	char	aa;
	char	ab;
	char	ba;
	char	bb;

	aa = '0';
	ab = '0';
	ba = '0';
	bb = '1';

	while(aa <= '9')
	{	
		if(ab >= '9')
		{
			ab = '0';
		}
		while(ab <= '9')
		{
			if(ba >= '9')
			{
				ba = '0';
			}
			while(ba <= '9')
			{
				if(bb >= '9')
				{
					/*reset variables to 0 to ensure all numbers are printed out
					 * and so the loop continues */
					bb = '0';
				}
				while(bb <= '9')
				{
					printchar(aa);
					printchar(ab); 
					write(1, " ", 1);
					printchar(ba);
					printchar(bb);
					
					if (aa != '9' || ab != '9' || ba !='9' || bb != '9')
					/* add spacing between the above writes */
					{
						write(1, ", ", 2);
					}
					bb++;
				}
				ba++;
			}
			ab++;
		}
		aa++;	


	}

	
}

int main()
{	
	ft_print_comb();
	return 0;
}
