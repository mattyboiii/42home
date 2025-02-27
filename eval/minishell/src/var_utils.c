/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:41 by mexu              #+#    #+#             */
/*   Updated: 2024/11/20 22:47:43 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the character is valid for a variable
static bool	is_var_compliant(char c)
{
	if (!ft_isalnum(c) && c != '_')
		return (false);
	else
		return (true);
}

// get the new string for the token
// with the variable value and the new size
char	*get_new_string(char *oldstr, char *var_value,
			int newstr_size, int index)
{
	char	*new_str;
	char	*new_p;
	char	*old_p;

	new_str = malloc(sizeof(char) * newstr_size);
	if (!new_str)
		return (NULL);
	new_p = new_str;
	old_p = oldstr;
	while (*old_p)
	{
		if (*old_p == '$' && old_p == oldstr + index)
		{
			while (var_value && *var_value)
				*new_p++ = *var_value++;
			old_p += var_length(oldstr + index) + 1;
			if (*old_p == '\0')
				break ;
		}
		*new_p++ = *old_p++;
	}
	*new_p = '\0';
	return (new_str);
}

// get the length of the variable
int	var_length(char *str)
{
	int	count;

	count = 0;
	while (*str != '$')
		str++;
	str++;
	if ((*str >= '0' && *str <= '9') || *str == '?')
		return (count + 1);
	while (*str && is_var_compliant(*str))
	{
		count++;
		str++;
	}
	return (count);
}
