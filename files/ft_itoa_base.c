#include <stdlib.h>
#include <stdio.h>


char	*ft_itoa_base(int value, int base)
{
	int		len;
	int		sign;
	unsigned int 	num;
	char		*digits = "0123456789ABCDEF";
	char		*str;

	len = 0;
	sign = 0;
	num = value;
	if (value == 0)
	{
		str = malloc(sizeof(char) * 1 + 1);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (base == 10 && value < 0)
	{
		sign = 1;
		len++;
	}
	else if (value < 0)
		num = value * -1;
	else
		num = value;
	while (num > 0)
	{
		num /= base;
		len++;
	}
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (value < 0)
		num = value * -1;
	else
		num = value;
	while (num)
	{
		str[--len] = digits[num % base];
		num /= base;
	}
	if (base == 10 && sign)
		str[0] = '-';
	return (str);
}
/*
char	*ft_itoa_base1(int value, int base) {
	int		i = 0, j = 1;
	char	temp[16], *final = NULL;

	if (base >= 2) {
		if (value < 0) {
			value = -value;
			temp[i] = '-';
			i++;
		}
		while (value) {
			temp[i] = value % base;
			value /= base;
			i++;
		}
		if ((final = (char *)malloc(sizeof(char) * (i + 1))) == ((void *)0))
			return ((void *)0);
		if (temp[0] == '-')
			final[0] = temp[0];
		while (i > 1) {
			--i;
			if (temp[i] < 10)
				final[j] = temp[i] + '0';
			if (temp[i] >= 10)
				final[j] = temp[i] - 10 + 'A';
			j++;
		}
		final[j] = '\0';
	}
	return (final);
}

int	main(int arc, char *arv[])
{
	char *str;
	char *str1;
	int	numn = atoi(arv[1]);
	int	num = atoi(arv[1]);
	int	base = atoi(arv[2]);
	numn *= -1;
	if (arc == 3)
	{
		str = ft_itoa_base(num, base);
		str1 = ft_itoa_base(num, base);
		printf("num: %d, base: %d\n", num, base);
		printf("myres: %s\n", str);
		printf("pcres: %s\n", str1);
		
		str = ft_itoa_base(numn, base);
		str1 = ft_itoa_base(numn, base);
		printf("num: %d, base: %d\n", numn, base);
		printf("myres: %s\n", str);
		printf("pcres: %s\n", str1);
	}
}
*/

