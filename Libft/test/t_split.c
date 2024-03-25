
#include "libft.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string> <delimiter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *string = argv[1];
    char delimiter = argv[2][0];

    // Call ft_split to split the string using the delimiter
    char **result = ft_split(string, delimiter);
    if (result == NULL) {
        printf("ft_split failed: Memory allocation error\n");
        return EXIT_FAILURE;
    }

    // Print each substring from the resulting array of strings
    for (int i = 0; result[i] != NULL; i++) {
        printf("Substring %d: \"%s\"\n", i+1, result[i]);
    }

    // Free memory allocated for the array of strings
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return EXIT_SUCCESS;
}
