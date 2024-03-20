#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	tt_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

int main() {
    char dest[20] = "Sharks";
    const char *src = "Baby!";
    size_t destsize = 5;

    printf("Dest string: %s\n", dest);
    printf("Srce string: %s\n", src);

    // Using ft_strlcat
    char ft_dest[20];
    strcpy(ft_dest, dest); // Making a copy for fair comparison
    size_t ft_result = ft_strlcat(ft_dest, src, destsize);

    // Using tt_strlcat
    char std_dest[20];
    strcpy(std_dest, dest); // Making a copy for fair comparison
    size_t std_result = tt_strlcat(std_dest, src, destsize);
    printf("Conc string ftstrlcat: %s\n", ft_dest);
    printf("Conc string ttstrlcat: %s\n", std_dest);
    printf("Total length of conc ftstrlcat: %zu\n", ft_result);
    printf("Total length of conc tt_strlcat: %zu\n", std_result);

    return 0;
}

