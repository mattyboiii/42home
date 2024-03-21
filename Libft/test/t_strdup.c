#include "libft.h"

int	main(void)
{
	char original[] = "Sharks!";
	char *dupog = ft_strdup(original);

	printf("%s\n", original);
	printf("%s\n", dupog);
	free(dupog);

	return (0);
}
