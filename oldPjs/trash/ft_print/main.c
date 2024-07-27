#include "ft_printf.h"
#include <stdio.h> // For standard printf comparison

int main(void) {
    int count;
    char *ptr = "hey"; // Declaring a char pointer variable
    
    // Test cases
    count = ft_printf("Hello, World!\n");
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("Character: %c\n", 'A');
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("String: %s\n", "Test string");
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("Pointer: %p\n", ptr); // Using the char pointer variable
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("Decimal: %d\n", -80000);
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("Decimal: %i\n", 422);
    printf("Custom printf: %d characters printed.\n", count);
    
    count = ft_printf("Unsigned: %u\n", -42);
    printf("regular printf: %u\n", -42);
    printf("Custom printf: %d characters printed.\n", count);

    count = ft_printf("Hex lower: %x\n", 60);
    printf("Custom printf: %d characters printed.\n", count);

    count = ft_printf("Hex upper: %X\n", 60);
    printf("Custom printf: %d characters printed.\n", count);

    count = ft_printf("Percent: %%\n");
    printf("Custom printf: %d characters printed.\n", count);
    
    return 0;
}

