#include "libft.h"

int main() {
    // Define a static string to test ft_split
    char *string = "             ";
    char delimiter = ' '; // You can choose any delimiter you want to test with

    // Call ft_split to split the static string using the delimiter
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