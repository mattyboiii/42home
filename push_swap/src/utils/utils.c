/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:31:05 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/30 16:42:33 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit(int n)
{
	if (n == 3)
	{
		ft_putendl_fd("Error", 1);
		exit(3);
	}
}

void	error_check_arv(char **arv)
{
	int		i;
	int		j;

	if (arv == NULL)
		ft_exit(3);
	i = 0;
	while (arv[i])
	{
		j = 0;
		if (arv[i][0] == '/')
			i++;
		while ((arv[i][j]))
		{
			if (ft_isdigit(arv[i][j]) == 1)
				j++;
			else
				ft_exit(3);
		}
		if (ft_atoi(arv[i]) > INT_MAX)
			ft_exit(3);
		else if (ft_atoi(arv[i]) < INT_MIN)
			ft_exit(3);
		i++;
	}
}
