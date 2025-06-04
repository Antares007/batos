#define TWORD_IMPLEMENTATION
#define Ext long d
#define E d

#include "tword.h"

static char str[1024];
static char color[1024];
extern int printf(const char *restrict __format, ...);
S(b_nl) {
  static char toTermColor[] = {4, 2, 3, 1};
  for (long i = 0; i < d; i++)
    printf("\033[30;4%dm%c\033[0m", toTermColor[color[i]], str[i]);
  printf("\n");
  return ok(C, d);
}
#define Length 10
#define Term(n)                                                                \
  S(b_##n) {                                                                   \
    return (Length == d ? 0 : (str[d] = #n[0], color[d] = b, ok(C, d + 1)));   \
  }

Term(a) Term(t) Term(i) Term(m) Term(p) Term(b) Term(s) Term(n) Term(w);

int main() {
  long o[2048];
  long s = 0;
#define D(S) o[s++] = 1, o[s++] = d_##S
#define B(b) o[s++] = 2, o[s++] = b_##b
#define T(S) o[s++] = 3, o[s++] = d_##S
  enum { d_S, d_s, d_np, d_vp, d_pp, d_det, d_noun, d_verb, d_prep };
  D(S), T(s), B(nl);
  D(s), T(np), T(vp);
  D(s), T(s), T(pp);
  D(np), T(noun);
  D(np), T(det), T(noun);
  D(np), T(np), T(pp);
  D(pp), T(prep), T(np);
  D(vp), T(verb), T(np);
  D(det), B(a);
  D(det), B(t);
  D(noun), B(i);
  D(noun), B(m);
  D(noun), B(p);
  D(noun), B(b);
  D(verb), B(s);
  D(prep), B(n);
  D(prep), B(w);
  o[s++] = 0;

  grow_toti_with_Yellow_pith(Pink, o, 0, 0, s, 0);
  return 0;
}
