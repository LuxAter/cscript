#include "prompt.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t history_length = 0;
static size_t history_index = 0;
static char** prompt_history = NULL;

void cscript_prompt_init(size_t length)
{
  history_length = length;
  prompt_history = (char**)malloc(length * sizeof(char*));
  for (unsigned i = 0; i < history_length; ++i) {
    prompt_history[i] = NULL;
  }
}

void cscript_prompt_term()
{
  for (unsigned i = 0; i < history_length; ++i) {
    if (prompt_history[i])
      free(prompt_history[i]);
  }
  free(prompt_history);
}

char* cscript_prompt_readline(const char* prompt)
{
  char* input = malloc(255 * sizeof(char));
  fputs(prompt, stdout);
  fgets(input, 255, stdin);
  prompt_history[history_index] = input;
  history_index = (history_index + 1) % history_length;
  return input;
}
char* cscript_prompt_get_history(size_t i)
{
  return prompt_history[i];
}
