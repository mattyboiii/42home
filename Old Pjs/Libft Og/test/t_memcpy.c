#include "libft.h"

int main() {
    char src[] = "Sharks Baby!!";
    char dest[20];

    // Test ft_memcpy
    printf("Testing ft_memcpy:\n");
    printf("Source string: %s\n", src);
    printf("Before ft_memcpy, dest string: %s\n", dest);

    ft_memcpy(dest, src, strlen(src) + 1);

    printf("After ft_memcpy, dest string: %s\n", dest);

    return 0;
}
