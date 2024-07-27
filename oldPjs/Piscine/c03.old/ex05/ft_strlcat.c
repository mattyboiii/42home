/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:41:14 by mtripodi          #+#    #+#             */
/*   Updated: 2023/11/30 10:52:20 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char *ft_strlcat(char *dest, char *src, unsigned int size:)
{
	int c;
	int i;

	c = 0;
	i = 0;
	while (str[c] != '\0')
	{
		while (str[c] == to_find[i] && (str[i] != '\0' || to_find[i] != '\0'))
		{
			c++;
			i++;
			if (to_find[i] == '\0')
				return (&str[c - i]);
		}
		c++;
		i = 0;
	}
	return (NULL);
}
/*
int main(void)
{
	char string[50] = "Zebra";
	char matching[] = "Zebra";
	char higher[] = "ant";
	char less[] = "ebra";
	char str2cm[] = "ebre";
	char str2cdh[] = "a";
	char str2cdl[] = "eb";

	printf("string vs matching: %s\n", ft_strlcat(string, matching, 50));
	printf("string vs higher: %s\n", ft_strlcat(string, higher, 50));
	printf("string vs less: %s\n", ft_strlcat(string, less, 50));
	printf("string vs str2char matching: %s\n", ft_strlcat(string, str2cm, 50));
	printf("string vs str2char higher: %s\n", ft_strlcat(string, str2cdh, 50));
	printf("string vs str2char lower: %s\n", ft_strlcat(string, str2cdl, 50));

	printf("\nactual function below\n");
	printf("string vs matching: %s\n", strlcat(string, matching, 50));
	printf("string vs higher: %s\n", strlcat(string, higher, 50));
	printf("string vs less: %s\n", strlcat(string, less, 50));
	printf("string vs str2char matching: %s\n", strlcat(string, str2cm, 50));
	printf("string vs str2char higher: %s\n", strlcat(string, str2cdh, 50));
	printf("string vs str2char lower: %s\n", strlcat(string, str2cdl, 50));

	return (0);
}
*/
