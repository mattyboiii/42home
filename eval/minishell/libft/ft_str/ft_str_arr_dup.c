/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:58:22 by mexu              #+#    #+#             */
/*   Updated: 2024/11/07 09:58:38 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicate a 2d string array
char	**ft_str_arr_dup(char **arr)
{
	char	**copy;
	int		i;

	if (arr == NULL)
		return (NULL);
	copy = ft_calloc(ft_str_arr_len(arr) + 1, sizeof(*copy));
	if (!copy)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		copy[i] = ft_strdup(arr[i]);
		i++;
	}
	return (copy);
}
