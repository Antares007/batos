#define TWORD_IMPLEMENTATION
#define Ext long d
#define E d

#include "tword.h"

static char str[1024];
static char color[1024];
extern int printf(const char *restrict __format, ...);
S(term_nl) {
  static char toTermColor[] = {4, 2, 3, 1};

  for (long i = 0; i < d; i++)
    printf("\033[30;4%dm%c\033[0m", toTermColor[color[i]], str[i]);
  printf("\n");
  return ok(C, d);
}
#define Length 10
#define Term(n)                                                                \
  S(term_##n) {                                                                \
    return (Length == d ? 0 : (str[d] = #n[0], color[d] = b, ok(C, d + 1)));   \
  }
Term(t) Term(a) Term(b) Term(o) Term(1) Term(2) Term(3);

// book oriented programming
// book operator?

long calculator(long arg_grammar, long *o, long s);
#include <stdio.h>
int main() {
  long o[2048];
  long s = 0;
#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = term_##b
#define T(S) o[s++] = 3, o[s++] = S

  D('_'), T('A'), B(nl);
  D('_'), B(nl);
  D('_'), T('S'), B(nl);
  D('_'), B(nl);

  D('T'), B(t);
  D('N'), B(1);
  D('T'), B(a);
  D('3'), T('T'), T('T'), T('T');
  D('N'), B(2);
  D('N'), B(3);
  D('T'), B(b);

  D('S'), B(b);
  D('S'), T('S'), B(a);
  D('S'), T('S'), B(t), T('O');
  D('O');
  D('O'), B(o);

  D('A'), B(a);
  D('A'), T('B'), B(o);
  D('B'), B(b);
  D('B'), T('A'), B(t);

  o[s++] = 0;
  o[s++] = 0;

  grow_toti_with_Yellow_pith(Pink, o, 0, 0, s, 0);
  return 0;
}
