/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:06:15 by mtripodi          #+#    #+#             */
/*   Updated: 2023/12/01 11:56:06 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *dup;
	int i;
	int len;

	len = 0;
	while (src[len] != '\0')
		len++;

	dup = malloc(len + 1);
	i = 0;
	if (dup == NULL)
		return NULL;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);


}


int	main(void)
{
	char original[] = "Sharks!";
	char *dupog = ft_strdup(original);

	printf("%s\n", original);
	printf("%s\n", dupog);
	free(dupog);

	return (0);
}

