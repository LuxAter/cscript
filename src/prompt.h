#ifndef CSCRIPT_PROMPT_H_
#define CSCRIPT_PROMPT_H_

#include <stdlib.h>

void cscript_prompt_init(size_t length);
void cscript_prompt_term();

char* cscript_prompt_readline(const char* prompt);
char* cscript_prompt_get_history(size_t i);

#endif  // CSCRIPT_PROMPT_H_
