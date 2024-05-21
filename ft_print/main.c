#include "ft_printf.h"
#include <stdio.h> // For standard printf comparison

int main(void) {
	int count;
	
	// Test cases
	count = ft_printf("Hello, World!\n");
	printf("Custom printf: %d characters printed.\n", count);
	
	count = ft_printf("Character: %c\n", 'A');
	printf("Custom printf: %d characters printed.\n", count);
	
	count = ft_printf("String: %s\n", "Test string");
	printf("Custom printf: %d characters printed.\n", count);
/*

	count = ft_printf("Pointer: %p\n", main);
	printf("Custom printf: %d characters printed.\n", count);

	count = ft_printf("Decimal: %d\n", 42);
	printf("Custom printf: %d characters printed.\n", count);

	count = ft_printf("Unsigned: %u\n", 42);
	printf("Custom printf: %d characters printed.\n", count);

	count = ft_printf("Hex lower: %x\n", 42);
	printf("Custom printf: %d characters printed.\n", count);

	count = ft_printf("Hex upper: %X\n", 42);
	printf("Custom printf: %d characters printed.\n", count);

	count = ft_printf("Percent: %%\n");
	printf("Custom printf: %d characters printed.\n", count);
*/
	return 0;
}

