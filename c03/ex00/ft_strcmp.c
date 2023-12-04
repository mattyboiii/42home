/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:02:35 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/04 10:36:45 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)	
{
	char string[] = "Zebra";
	char matching[] = "Zebra";
	char higher[] = "ant";
	char less[] = "Abc";
	char str2cm[] = "Ze";
	char str2cdh[] = "Za";
	char str2cdl[] = "Zz";

	printf("string vs matching: %d\n", ft_strcmp(string, matching));
	printf("string vs higher: %d\n", ft_strcmp(string, higher));
	printf("string vs less: %d\n", ft_strcmp(string, less));
	printf("string vs str2char matching: %d\n", ft_strcmp(string, str2cm));
	printf("string vs str2char higher: %d\n", ft_strcmp(string, str2cdh));
	printf("string vs str2char lower: %d\n", ft_strcmp(string, str2cdl));

	printf("actual function below\n");
	printf("string vs matching: %d\n", strcmp(string, matching));
	printf("string vs higher: %d\n", strcmp(string, higher));
	printf("string vs less: %d\n", strcmp(string, less));
	printf("string vs str2char matching: %d\n", strcmp(string, str2cm));
	printf("string vs str2char higher: %d\n", strcmp(string, str2cdh));
	printf("string vs str2char lower: %d\n", strcmp(string, str2cdl));
	return (0);
}
*/
