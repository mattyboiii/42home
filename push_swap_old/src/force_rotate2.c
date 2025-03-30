/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_rotate2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-09 22:22:39 by mtripodi          #+#    #+#             */
/*   Updated: 2025-02-09 22:22:39 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief PLEASE READ this is the last function I made. It is used to check
 * both force directions. Then, most importantly, tell the t_hold hold->rotate
 * which forced direction is the most efficient.
 *
 * What did this prevent? Well below, You can see numbers. The only hold
 * selected is #6 1006084697. This belongs underneath #5-2 1024488110 and
 * above #6-2 974173097.
 *
 * M previous code, would return 7 actions possible. But because the hold is
 * below the middle of the stack, which in this example. Would reverse rotate
 * the entire B stack, untill 6-2 was on top. meaning it would run rrb 90+
 * times, instead of using rrr 6 times, then pushing with pb, to make 7.
 *
 * now, I will try both directions of force, then depending on the fastest
 * direction, I will set hold->rotate to accomodate this. 1, being rr, -1
 * being rrr. As rotate_run() checks if rotate >= 0.
 *
 * @return It returns the shortest number of actions possible with
 * force_rotate. But importanlty, it sets hold->rotate to eitehr 1 or -1
 *
 * a  [0]: 2098301628-----  b  [0-2]: 1309191291
	a  [1]: 2050063390-----  b  [1-2]: 1216063712
	a  [2]: 1807553064-----  b  [2-2]: 1178562086
	a  [3]: 1898062055-----  b  [3-2]: 1052548554
	a  [4]: 2023393510-----  b  [4-2]: 1034444711
	a  [5]: 1921336557-----  b  [5-2]: 1024488110
	a  [6]: 1006084697-----  b  [6-2]: 974173097
                      -----  b  [7-1]: 757974271
                      -----  b  [8-1]: 728608840
                      -----  b  [9-1]: 724228848
                      -----  b [10-1]: 702519521
                      -----  b [11-1]: 647931696
                      -----  b [12-1]: 646652632
                      -----  b [13-1]: 635017449
                      -----  b [14-1]: 601300955
                      -----  b [...]
                      -----  b [79-2]: 1664652563
                      -----  b [80-2]: 1592627117
                      -----  b [81-2]: 1588495331
                      -----  b [82-2]: 1560937734
                      -----  b [83-2]: 1516805228
                      -----  b [84-2]: 1470417827
                      -----  b [85-2]: 1467870695
                      -----  b [86-2]: 1438200106
                      -----  b [87-2]: 1395677521
                      -----  b [88-2]: 1381121552
                      -----  b [89-2]: 1376331248
                      -----  b [90-2]: 1335286931
                      -----  b [91-2]: 1324223016
                      ----  b [92-2]: 1319692087
*/
int	check_rrr_rr(t_stacks stack, t_node *fr_hold, t_hold *hold)
{
	int		rr;
	int		rrr;

	rr = force_rotate_check(stack, fr_hold, 1);
	rrr = force_rotate_check(stack, fr_hold, -1);
	if (rr <= rrr)
	{
		if (hold->compare == 0 || posnum(hold->compare) < rr)
			hold->rotate = 1;
		return (rr);
	}
	else
	{
		if (hold->compare == 0 || posnum(hold->compare) < rrr)
			hold->rotate = -1;
		return (rrr * -1);
	}
}
