#include "../push_swap.h"

void	sort3(t_node *a)
{
	t_node		*small;
	t_node		*big;

	while (a->next)
	{
		small = a;
		big = a;
		a = a->next;
		if (a->num < small->num)
			small = a;
		else if (a->num > big->num)
			big = a;
	}
	if (big->pos < 2)
	{
		
	// make sure that if a number is bigger than one, and smaller than anotehr its the middle number. 

	// if top number is the smallest. 

	// if the middle number is the biggest

	// if the bottom number is the biggest?
}