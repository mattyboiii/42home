#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Open the file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Read lines from the file using get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line); // Free memory allocated by get_next_line
    }

    // Close the file
    close(fd);

    return 0;
}