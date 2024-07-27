#include "libft.h"

int main() {
    char str[20] = "Sharks Baby!!";
    size_t len = 20; // Use the size of the array, not the length of the string

    // Print the original string
    printf("Original string: %s\n", str);

    // Call ft_bzero to zero out the string
    ft_bzero(str, len);

    // Print the modified string after calling ft_bzero
    printf("Modified string: %s\n", str);

    // Check if the memory is zeroed out
    int zeroed = 1;
    size_t i = 0;
    while (i < len) {
        if (str[i] != '\0') {
            zeroed = 0;
            break;
        }
        i++;
    }
    if (zeroed) {
        printf("ft_bzero successful!\n");
    } else {
        printf("ft_bzero failed!\n");
    }

    return 0;
}

