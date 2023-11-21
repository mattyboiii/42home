

#include <stdio.h>
/*data_type *pointer_value
 *
 * int *ptr points to integer value address
 * char *ptr points to char pointer value. 
 */



int x = 5;

int main()
{
	int i = 1;
	int *p = &i;
	printf("%d", *p);
}
		  
