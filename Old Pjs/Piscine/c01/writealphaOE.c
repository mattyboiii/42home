#include <unistd.h>

void ft_alpha_cool(void)
{
	write(1, "AbC\n", 4);
}

int main()
{
	ft_alpha_cool();
}
