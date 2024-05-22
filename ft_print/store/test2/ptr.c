#include <stdio.h>

int main() {
  int num = 10;
  int *ptr = &num; // ptr is an integer pointer that stores the address of num

  printf("Address of num stored in ptr: %p\n", ptr);

  return 0;
}

