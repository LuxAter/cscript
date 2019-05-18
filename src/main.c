#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* #include "prompt.h" */
#include <editline/readline.h>

int main(int argc, char* argv[])
{
  while (true) {
    char* input = readline(">> ");
    add_history(input);
    printf(">>%s<<\n", input);
    free(input);
  }
  return 0;
}
