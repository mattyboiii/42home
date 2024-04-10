#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Sharks";
    const char *src = "Baby!";
    size_t destsize = 0;

    printf("Dest string: %s\n", dest);
    printf("Srce string: %s\n", src);

    // Using ft_strlcat
    char ft_dest[20];
    strcpy(ft_dest, dest); // Making a copy for fair comparison
    size_t ft_result = ft_strlcat(ft_dest, src, destsize);

    // Using strlcat
    char std_dest[20];
    strcpy(std_dest, dest); // Making a copy for fair comparison
    size_t std_result = strlcat(std_dest, src, destsize);
    printf("Conc string ftstrlcat: %s\n", ft_dest);
    printf("Conc string ttstrlcat: %s\n", std_dest);
    printf("Total length of conc ftstrlcat: %zu\n", ft_result);
    printf("Total length of conc strlcat: %zu\n", std_result);

    return 0;
}

