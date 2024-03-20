#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int	main(void)
{
	char string[50] = "ZebZebra";
	char matching[] = "ZebZebra";
	char ant[] = "ant";
    char blank[] = "";
	char Abc[] = "Abc";
	char Zeb[] = "Zeb";
	char Za[] = "Za";
	char ZZ[] = "Zz";

	printf("string vs matching: %s\n", ft_strnstr(string, matching, 10));
	printf("string vs ant: %s\n", ft_strnstr(string, ant, 10));
	printf("string vs blank: %s\n", ft_strnstr(string, blank, 10));
	printf("string vs Abc: %s\n", ft_strnstr(string, Abc, 10));
	printf("string vs Zeb: %s\n", ft_strnstr(string, Zeb, 10));
	printf("string vs Za: %s\n", ft_strnstr(string, Za, 10));
	printf("string vs ZZ: %s\n", ft_strnstr(string, ZZ, 10));

	printf("\nactual function below\n");
	printf("string vs matching: %s\n", strnstr(string, matching, 10));
	printf("string vs ant: %s\n", strnstr(string, ant, 10));
	printf("string vs blank: %s\n", strnstr(string, blank, 10));
	printf("string vs Abc: %s\n", strnstr(string, Abc, 10));
	printf("string vs Zeb: %s\n", strnstr(string, Zeb, 10));
	printf("string vs Za: %s\n", strnstr(string, Za, 10));
	printf("string vs ZZ: %s\n", strnstr(string, ZZ, 10));

	return (0);
}
