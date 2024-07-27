/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:28:09 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/09 16:34:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*originaldest;

	originaldest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (originaldest);
}

char	*retempty(void)
{
	char	*result;

	result = malloc(1);
	if (result == NULL)
	{
		return (NULL);
	}
	*result = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	size_t	total_length;
	int		i;

	total_length = 0;
	i = 0;
	if (size == 0)
		return (retempty());
	while (i < size)
		total_length += ft_strlen(strs[i++]);
	total_length += (size - 1) * ft_strlen(sep) + 1;
	result = malloc(total_length);
	if (result == NULL)
		return (NULL);
	*result = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
/*
int main()
{
	char *strs[] = {"Hello", "World", "123", "456"};
	char *sep = " - ";
	char *result = ft_strjoin(4, strs, sep);
	
	if (result != NULL)
	{
		printf("Result: %s\n", result);
		free(result);
	}

	return 0;
}
*/
