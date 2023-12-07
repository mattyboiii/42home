/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:02:35 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/04 10:37:56 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
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
int	main(void)	
{
	char string[] = "Zebra";
	char matching[] = "Zebra";
	char higher[] = "ant";
	char less[] = "Abc";
	char str2cm[] = "Ze";
	char str2cdh[] = "Za";
	char str2cdl[] = "Zz";

	printf("string vs matching: %d\n", ft_strncmp(string, matching, 3));
	printf("string vs higher: %d\n", ft_strncmp(string, higher, 3));
	printf("string vs less: %d\n", ft_strncmp(string, less, 3));
	printf("string vs str2char matching: %d\n", ft_strncmp(string, str2cm, 2));
	printf("string vs str2char higher: %d\n", ft_strncmp(string, str2cdh, 2));
	printf("string vs str2char lower: %d\n", ft_strncmp(string, str2cdl, 2));

	printf("actual function below\n");
	printf("string vs matching: %d\n", strncmp(string, matching, 3));
	printf("string vs higher: %d\n", strncmp(string, higher, 3));
	printf("string vs less: %d\n", strncmp(string, less, 3));
	printf("string vs str2char matching: %d\n", strncmp(string, str2cm, 2));
	printf("string vs str2char higher: %d\n", strncmp(string, str2cdh, 2));
	printf("string vs str2char lower: %d\n", strncmp(string, str2cdl, 2));
	return (0);
}
