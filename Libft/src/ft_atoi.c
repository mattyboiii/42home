/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:38:14 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/21 12:17:30 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//     The atoi() function converts the initial portion of the string pointed to by
//     str to int representation.
//
//     It is equivalent to:
//
//           (int)strtol(str, (char **)NULL, 10);
//
//    While the atoi() function uses the current locale, the atoi_l() function may
//     be passed a locale directly. See xlocale(3) for more information.
//
// IMPLEMENTATION NOTES
//     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
//
//     The strtol() and strtol_l() functions are recommended instead of atoi() and
//     atoi_l() functions, especially in new code.

// Recommendation:
// The description also mentions that strtol() and strtol_l() functions are
// recommended over atoi() and atoi_l() functions, especially in new code.
// This is because strtol() provides more control and flexibility, making it
// more robust for string to integer conversions.
//
// To recreate the atoi() function, you would essentially need to implement
// a function that takes a string as input, parses it, and converts it into
// an integer. You can follow the approach of strtol(), parsing the string
// and converting it into an integer based on your requirements.

int	atoi(const char *str)
{
	
}
