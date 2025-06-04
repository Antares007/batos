#define TWORD_IMPLEMENTATION
#define Ext long d, long *sum
#define E d, sum

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
S(term_1          ) { return (Length == d ? 0 : (str[d] = '1', ok(C, d + 1, (long[]){1, sum}))); };
S(term_2          ) { return (Length == d ? 0 : (str[d] = '2', ok(C, d + 1, (long[]){2, sum}))); };
S(term_3          ) { return (Length == d ? 0 : (str[d] = '3', ok(C, d + 1, (long[]){3, sum}))); };
S(term_open_paren ) { return (Length == d ? 0 : (str[d] = '(', ok(C, d + 1, sum))); };
S(term_close_paren) { return (Length == d ? 0 : (str[d] = ')', ok(C, d + 1, sum))); };
S(term_minus      ) { return (Length == d ? 0 : (str[d] = '-', ok(C, d + 1, sum))); };
S(term_plus       ) { return (Length == d ? 0 : (str[d] = '+', ok(C, d + 1, sum))); };
S(term_mul        ) { return (Length == d ? 0 : (str[d] = '*', ok(C, d + 1, sum))); };
S(term_div        ) { return (Length == d ? 0 : (str[d] = '/', ok(C, d + 1, sum))); };
S(term_bang       ) { return (Length == d ? 0 : (str[d] = '!', ok(C, d + 1, sum))); };

S(term_nl         ) { return (str[d] = '\0', printf("%3ld = %s\n", sum[0], str), ok(C, d, sum)); }

S(term_do_negate  ) { return ok(C, d, (long[]){-sum[0], sum[1]}); }
S(term_do_bang    ) { return ok(C, d, (long[]){!sum[0], sum[1]}); }
S(term_do_mul     ) { return ok(C, d, (long[]){((long**)sum)[1][0] * sum[0], ((long**)sum)[1][1]}); }
S(term_do_div     ) { return sum[0] ? ok(C, d, (long[]){((long**)sum)[1][0] / sum[0], ((long**)sum)[1][1]}) : 0; }
S(term_do_plus    ) { return ok(C, d, (long[]){((long**)sum)[1][0] + sum[0], ((long**)sum)[1][1]}); }
S(term_do_minus   ) { return ok(C, d, (long[]){((long**)sum)[1][0] - sum[0], ((long**)sum)[1][1]}); }

int main() {
  long o[2048];
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = term_##b
#define T(S) o[s++] = 3, o[s++] = S

  D(0),                         T(expression), B(nl);
  D(constant),                  B(1);
  D(constant),                  B(2);
  D(constant),                  B(3);

  D(primary_expression),        T(constant);
  D(primary_expression),        B(open_paren), T(expression), B(close_paren);

  D(unary_expression),          T(primary_expression);
  D(unary_expression),          B(minus), T(unary_expression), B(do_negate);
  D(unary_expression),          B(bang), T(unary_expression), B(do_bang);


  D(multiplicative_expression), T(unary_expression);
  D(multiplicative_expression), T(multiplicative_expression), B(mul),   T(unary_expression), B(do_mul);
  D(multiplicative_expression), T(multiplicative_expression), B(div),   T(unary_expression), B(do_div);

  D(additive_expression),       T(multiplicative_expression);
  D(additive_expression),       T(additive_expression),       B(plus),  T(multiplicative_expression), B(do_plus);
  D(additive_expression),       T(additive_expression),       B(minus), T(multiplicative_expression), B(do_minus);

  D(expression),                T(additive_expression);
  o[s++] = 0;

  grow_toti_with_Yellow_pith(Pink, o, 0, 0, s, 0, 0);
  return 0;
}
