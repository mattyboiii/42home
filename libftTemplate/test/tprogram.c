
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("test/test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
