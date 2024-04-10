
#include "libft.h" // Include your library containing ft_putnbr_fd

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number> <file_descriptor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse number and file descriptor from command line arguments
    int number = atoi(argv[1]);
    int fd = atoi(argv[2]);

    // Call ft_putnbr_fd to output the number to the specified file descriptor
    ft_putnbr_fd(number, fd);

    return EXIT_SUCCESS;
}
