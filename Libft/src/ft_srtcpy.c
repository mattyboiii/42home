char *ft_strcpy(char *dest, const char *src)
{
	char *ptr;
	size_t i;

	ptr = dest;

	i = 0;
	while (ptr[i] != '\0') 
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}
