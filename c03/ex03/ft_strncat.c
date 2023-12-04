/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:14:13 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/30 10:54:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				c;
	unsigned int	i;

	c = 0;
	while (dest[c] != '\0')
		c++;
	i = 0;
	while (i < nb)
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

	printf("string vs matching: %s\n", ft_strncat(string, matching, 3));
	printf("string vs higher: %s\n", ft_strncat(string, higher, 3));
	printf("string vs less: %s\n", ft_strncat(string, less, 3));
	printf("string vs str2char matching: %s\n", ft_strncat(string, str2cm, 2));
	printf("string vs str2char higher: %s\n", ft_strncat(string, str2cdh, 2));
	printf("string vs str2char lower: %s\n", ft_strncat(string, str2cdl, 2));

	printf("actual function below\n");
	printf("string vs matching: %s\n", strncat(string, matching, 3));
	printf("string vs higher: %s\n", strncat(string, higher, 3));
	printf("string vs less: %s\n", strncat(string, less, 3));
	printf("string vs str2char matching: %s\n", strncat(string, str2cm, 2));
	printf("string vs str2char higher: %s\n", strncat(string, str2cdh, 2));
	printf("string vs str2char lower: %s\n", strncat(string, str2cdl, 2));
	return (0);
}
*/
