#include "libft.h"

int main() {
    char src[] = "Sharks Baby!!";
    char dest[20];

    // Test ft_memmove
    printf("Testing ft_memmove:\n");
    printf("Source string: %s\n", src);
    printf("Before ft_memmove, dest string: %s\n", dest);

    ft_memmove(dest, src, strlen(src) + 1);

    printf("After ft_memmove, dest string: %s\n", dest);

    return 0;
}
