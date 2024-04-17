#include "libft.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *str = ft_itoa(n);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Integer: %d\nString: %s\n", n, str);
    free(str);
    return 0;
}
