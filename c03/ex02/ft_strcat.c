/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:34:42 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/29 20:13:28 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	i;

	c = 0;
	while (dest[c] != '\0')
		c++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[c] = src[i];
		i++;
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
/*
int	main(void)	
{
	char string[50] = "Zebra";
	char matching[] = "Zebra";
	char higher[] = "ant";
	char less[] = "Abc";
	char str2cm[] = "Ze";
	char str2cdh[] = "Za";
	char str2cdl[] = "Zz";

	printf("string vs matching: %s\n", ft_strcat(string, matching));
	printf("string vs higher: %s\n", ft_strcat(string, higher));
	printf("string vs less: %s\n", ft_strcat(string, less));
	printf("string vs str2char matching: %s\n", ft_strcat(string, str2cm));
	printf("string vs str2char higher: %s\n", ft_strcat(string, str2cdh));
	printf("string vs str2char lower: %s\n", ft_strcat(string, str2cdl));

	printf("\nactual function below\n");
	printf("string vs matching: %s\n", strcat(string, matching));
	printf("string vs higher: %s\n", strcat(string, higher));
	printf("string vs less: %s\n", strcat(string, less));
	printf("string vs str2char matching: %s\n", strcat(string, str2cm));
	printf("string vs str2char higher: %s\n", strcat(string, str2cdh));
	printf("string vs str2char lower: %s\n", strcat(string, str2cdl));
	return (0);
}
*/
