#include <stdio.h>
#include <unistd.h>


void printchar(char c)
{
	write(1, &c, 1);
}


void ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';

	while(a <= '7')
	{	
		b = a + 1;

		if(a == '0')
		{
			b = '0';	
		}

		while(b <= '8')
		{
			c = b + 1;

			while(c <= '9')
			{
				printchar(a);
				printchar(b);
				printchar(c);

				if (a != '7' || b != '8' || c !='9')
				{
					write(1, ", ", 2);
				}				
				c++;
			}
			b++;
		}
		a++;	


	}

	
}

int main()
{	
	ft_print_comb();
	return 0;
}
