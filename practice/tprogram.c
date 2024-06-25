#include <stdio.h>

// Simulate your ft_split function (replace with your actual implementation)
char **ft_split(char *str, char c);

int main() {
  char *str = "   One Two Three   ! ";
  char c = ' ';
  char **words;

  words = ft_split(str, c);

  if (words == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Print each word in the split array
  int i = 0;
  while (words[i] != NULL) {
    printf("%s\n", words[i]);
    i++;
  }

  return 0;
}

