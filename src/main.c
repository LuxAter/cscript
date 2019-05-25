#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum TOKENS { INTEGER,
  PLUS,
  MINUS,
  EOS };

typedef struct token {
  enum TOKENS type;
  union {
    char ch;
    int v;
  };
} token_t;

static char* text;
static unsigned pos;
static token_t current_token;

token_t get_next_token()
{
  if (pos > strlen(text) - 1) {
    token_t token;
    token.type = EOS;
    token.ch = '\0';
    return token;
  }
  if (text[pos] >= 48 && text[pos] <= 57) {
    token_t token;
    token.type = INTEGER;
    token.v = text[pos] - 48;
    pos++;
    return token;
  }
  if (text[pos] == '+') {
    token_t token;
    token.type = PLUS;
    token.ch = text[pos];
    pos++;
    return token;
  }else if(text[pos] == '-'){
    token_t token;
    token.type = MINUS;
    token.ch = text[pos];
    pos++;
    return token;
  }
  fprintf(stderr, "!\n");
}

void eat(enum TOKENS token_type)
{
  if (current_token.type == token_type) {
    current_token = get_next_token();
  } else {
    fprintf(stderr, "!!\n");
  }
}

int expr()
{
  current_token = get_next_token();
  token_t left = current_token;
  eat(INTEGER);
  token_t op = current_token;
  eat(PLUS);
  token_t right = current_token;
  eat(INTEGER);
  int result = left.v + right.v;
  return result;
}

int main(int argc, char* argv[])
{
  while (true) {
    printf("calc>");
    char buff[255];
    if (scanf("%s", buff) != 1) {
      break;
    }
    text = buff;
    pos = 0;
    printf("  %d\n", expr());
  }
  return 0;
}
