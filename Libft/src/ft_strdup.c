/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:06:15 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/21 15:23:40 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlude "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * len + 1);
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (*src)
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}
