#include <unistd.h>

void	print_hex(int num)
{
	char	*digits = "0123456789abcdef";
	char	digit;

	if (num >= 16)
		print_hex(num / 16);
	digit = digits[num % 16];
	write(1, &digit, 1);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}
int	main(int arc, char *arv[])
{
	if (arc == 2)
	{
		int	num;

		num = ft_atoi(arv[1]);
		if (num == 0)
			write(1, "0", 1);
		else
			print_hex(num);
	}
	write(1, "\n", 1);
}
