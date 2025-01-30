/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:31:05 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 15:25:12 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_negs(char **arv, int i)
{
	int		j;

	while (arv[i])
	{
		j = 0;
		while (arv[i][j])
		{
			if (arv[i][j] == '-' && j != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* checks if any arguments inside of arv have leading zeros. eg -01 02. It also
runs the str_negs function
*/
int	str_zeros(char **arv, int i)
{
	int		j;
	char	c;

	if (str_negs(arv, i) == 1)
		ft_exit(6);
	if (arv[i] == NULL)
		return (0);
	while (arv[i])
	{
		j = 0;
		if (arv[i][j] == '-')
			j++;
		c = arv[i][j];
		if (c == '0' && arv[i][j + 1] != 0)
			return (1);
		i++;
	}
	return (0);
}

/* checks if any argument inside of arv shows up twice in the array. If
it does, then it returns 1. if not 0.
*/
int	strdouble(char **arv, int i)
{
	int		j;

	if (!arv[1])
		return (0);
	if (arv[i][1] == '-')
		ft_exit(6);
	if (str_zeros(arv, i) == 1)
		ft_exit(6);
	while (arv[i])
	{
		j = i + 1;
		while (arv[j])
		{
			if (ft_strcmp(arv[i], arv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	str_many_check(char **arv, int i)
{
	int		j;

	while (arv[i])
	{
		j = 0;
		if (strdouble(arv, i) == 1)
			ft_exit(6);
		while ((arv[i][j]))
		{
			if (ft_isdigit(arv[i][j]) == 1 || ((arv[i][j]) == '-' && arv[i][j
			+ 1] != '-' && arv[i][j + 1]))
				j++;
			else
				ft_exit(6);
		}
		if ((ft_atoi(arv[i]) > INT_MAX) || (ft_atoi(arv[i]) < INT_MIN))
			ft_exit(6);
		i++;
	}
}

void	error_check_arv(char **arv)
{
	int		i;
	int		j;
	int		arc;

	i = 0;
	if (arv == NULL || *arv == NULL)
		ft_exit(0);
	if (arv[0][0] == '/' || arv[0][0] == '.')
		i = 1;
	arc = array_size(arv) - 1;
	if (arv[i] == NULL)
		ft_exit(0);
	if (arc == 1)
		ft_exit(6);
	str_many_check(arv, i);
}
