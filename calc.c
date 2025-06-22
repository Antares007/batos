#define TWORD_IMPLEMENTATION
#define Ext long d, long *r
#define E d, r
#define W 3

#include "tword.h"

enum {
  primary_expression = 127,
  unary_expression,
  expression,
  unary_operator,
  multiplicative_expression,
  additive_expression,
  constant,
};
#define Length 10
static char str[1024];
extern int printf(const char *restrict __format, ...);

// clang-format off
#define List(h,t) (long[]){h, (long*)t}
#define Head(l) l[0]
#define Tail(l) ((long*)l[1])
S(term         ) { return (Length == d ? 0 : (str[d] = ((char*)o[t + 2])[1], ok(C, d + 1, r))); }

S(nl         ) { return (str[d] = '\0', printf("%3ld = %s\n", r[0], str), ok(C, d, r)); }
S(is_80      ) { return r[0] == 80 ? ok(CE) : 0; }
S(do_1       ) { return           ok(C, d, List(1, r)); }
S(do_2       ) { return           ok(C, d, List(2, r)); }
S(do_3       ) { return           ok(C, d, List(3, r)); }
S(do_negate  ) { return           ok(C, d, List(-Head(r), Tail(r))); }
S(do_bang    ) { return           ok(C, d, List(!Head(r), Tail(r))); }
S(do_mul     ) { return           ok(C, d, List(Head(Tail(r)) * Head(r), Tail(Tail(r)))); }
S(do_div     ) { return Head(r) ? ok(C, d, List(Head(Tail(r)) / Head(r), Tail(Tail(r)))) : 0; }
S(do_plus    ) { return           ok(C, d, List(Head(Tail(r)) + Head(r), Tail(Tail(r)))); }
S(do_minus   ) { return           ok(C, d, List(Head(Tail(r)) - Head(r), Tail(Tail(r)))); }

S(book_of_print);
S(print_0) { return printf("0(0)\n");}
S(print_1) { return printf("\n%s → ", (char*)o[t+2]), book_of_print(b, o, t + W, u, s, E); }
S(print_2) { return printf("%s ", (char*)o[t+2]), book_of_print(b, o, t + W, u, s, E); }
S(print_3) { return printf("%s ", (char*)o[t+2]), book_of_print(b, o, t + W, u, s, E);}

S(book_of_print) {
  static n_t nars[] = {
    print_0,
    print_1,
    print_2,
    print_3,
  };
  return nars[o[t]](CE);
}
int main() {
  long o[2048];
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S,  o[s++] = #S
#define B(b) o[s++] = 2, o[s++] = b,  o[s++] = #b
#define T(S) o[s++] = 3, o[s++] = S,  o[s++] = #S
#undef C
#define C(b) o[s++] = 2, o[s++] = term, o[s++] = #b

  D(0),                         T(expression), B(is_80), B(nl);

  D(constant),                  C('1'), B(do_1);
  D(constant),                  C('2'), B(do_2);
  D(constant),                  C('3'), B(do_3);

  D(primary_expression),        T(constant);
  D(primary_expression),        C('('), T(expression), C(')');

  D(unary_expression),          T(primary_expression);
  D(unary_expression),          C('-'), T(unary_expression), B(do_negate);
  D(unary_expression),          C('!'), T(unary_expression), B(do_bang);

  D(multiplicative_expression), T(unary_expression);
  D(multiplicative_expression), T(multiplicative_expression), C('*'), T(unary_expression), B(do_mul);
  D(multiplicative_expression), T(multiplicative_expression), C('/'), T(unary_expression), B(do_div);

  D(additive_expression),       T(multiplicative_expression);
  D(additive_expression),       T(additive_expression),       C('+'), T(multiplicative_expression), B(do_plus);
  D(additive_expression),       T(additive_expression),       C('-'), T(multiplicative_expression), B(do_minus);

  D(expression),                T(additive_expression);
  o[s++] = 0;
  book_of_print(Pink, o, 0, 0, s, 0, 0);
  branch_and_grow_Yellow(Pink, o, 0, 0, s, 0, 0);
  return 0;
}
