#include "libft.h"

int main() {
    char dest[20] = "Sharks";
    const char *src = "Baby!";
    size_t destsize = sizeof(dest);

    printf("Initial destination string: %s\n", dest);
    printf("Source string: %s\n", src);

    size_t result = ft_strlcat(dest, src, destsize);

    printf("Concatenated string: %s\n", dest);
    printf("Total length of concatenated string: %zu\n", result);

    return 0;
}

