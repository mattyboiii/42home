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
	if (n == 2)
	{
		ft_putendl_fd("Error", 1);
		exit(2);
	}
	if (n == 10)
	{
		ft_putendl_fd("Error", 1);
		exit(10);
	}
}

/* checks if any argument inside of arv shows up twice in the array. If
it does, then it returns 1. if not 0.
*/
int	strdouble(char **arv)
{
	int		i;
	int		j;
	char	*str;

	if (arv == NULL)
		return (0);
	i = 0;
	while (arv[i])
	{
		j = 0;
		str = arv[i];
		while (str[j] && arv[i + 1])
		{
			if (str[j] != arv[i + 1][j])
				break ;
			j++;
		}
		if ((int)ft_strlen(str) == j && ft_strlen(arv[i + 1]) == j)
			return (1);
		i++;
	}
	return (0);
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
		if (strdouble(arv) == 1)
			ft_exit(2);
		if (arv[i][0] == '/')
			i++;
		while ((arv[i][j]))
		{
			if (ft_isdigit(arv[i][j]) == 1 || ((arv[i][j]) == '-' &&
						arv[i][j + 1] != '-'))
				j++;
			else
				ft_exit(3);
		}
		if ((ft_atoi(arv[i]) > INT_MAX) || (ft_atoi(arv[i]) < INT_MIN))
			ft_exit(10);
		i++;
	}
}

