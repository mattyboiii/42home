/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:50:15 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/21 11:01:44 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to free memory, but most importanly set the pointers to NULL aft    er
// freeing. This helps me debug my programs. Freeing the pointers to NULL
// is the reason the function is a tripple ptr eg ***ptr. As i want to 
// set **ptr to NULL.
void	dp_free(char ***dp)
{
	int	i;

	i = 0;
	while ((*dp)[i])
	{
		null_free(&(*dp)[i]);
		i++;
	}
	free(*dp);
	*dp = NULL;
}
