#include "libft.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string> <set>\n", argv[0]);
        return 1;
    }

    char *trimmed = ft_strtrim(argv[1], argv[2]);
    if (trimmed == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original string: %s\n", argv[1]);
    printf("Set to trim: %s\n", argv[2]);
    printf("Trimmed string: %s\n", trimmed);

    free(trimmed);
    return 0;
}
