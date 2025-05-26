// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"

#define _STR(s) #s
#define STR(s) _STR(s)

#define Chapter                                                                \
  __attribute__((section(".text." __FILE_NAME__ STR(__LINE__))))               \
  __attribute__((__noinline__)) __attribute__((used))
#define ChapterSize 512

#include <stdio.h>
#define Context void*b, long *o, long t, struct Quattro *q, long s, long*u
#define N(argo) long argo(Context)
#define C b, o, t, q, s
typedef struct Ray {
  struct Quattro*upper;
  long t;
  N((*partition));
  N((*new_partition));
  N((*continue_or_return_to_next));
  N((*clr));
} Ray;
typedef struct Quattro {
  Ray*Blue;
  Ray*Green;
  Ray*Yellow;
  Ray*Red;
} Quattro;
typedef N((*n_t));
#define S(argo) static N(argo)

S(Blue_0); S(Green_0); S(Yellow_0); S(Red_0);
S(bo) { return (((n_t)b) + o[t] * ChapterSize)(C, u); }

Chapter S(Blue_0  ) { return t; }
Chapter S(Blue_1  ) { Quattro*p = q; int depth = 0; while(p) p = p->Blue->upper, depth++;
                      if (7 < depth) return t;
                      if (o[q->Blue->t + 1] == o[t + 1]) bo(q->Blue->new_partition, o, t + 2, q, s, u);
                      return bo(b, o, t + 2, q, s, u); }
Chapter S(Blue_2  ) { return bo(b, o, t + 2, q, s, u); }
Chapter S(Blue_3  ) { return bo(b, o, t + 2, q, s, u); }

S(clr_top         ) { return o[q->Blue->t + 1] == o[t + 1]; }
S(clr             ) { return o[q->Blue->t + 1] == o[t + 1] ? 2 : q->Blue->upper->Blue->clr(b, o, t, q->Blue->upper, s, u); }
S(cont            ) { return bo(b, o, q->Blue->t + 2, q->Blue->upper, s, u); }
S(upper_cont      ) { return q->Blue->upper->Blue->continue_or_return_to_next(b, o, t, q->Blue->upper, s, u); }

Chapter S(Green_0 ) { q->Blue->continue_or_return_to_next(C, u);
                      Ray r = { .upper = q,
                                .t = q->Blue->t,
                                .partition = b,
                                .new_partition = Red_0,
                                .continue_or_return_to_next = upper_cont,
                                .clr = clr_top};
                      return bo(Blue_0, o, 0, &(Quattro){&r, q->Green, q->Yellow, q->Red}, s, u); }
Chapter S(Green_1 ) { return Green_0(C, u); }
Chapter S(Green_2 ) { return ((n_t)o[t + 1])(C, u); }
Chapter S(Green_3 ) { Ray r = { .upper = q,
                                .t = t,
                                .partition = b,
                                .new_partition = Yellow_0,
                                .continue_or_return_to_next = cont,
                                .clr = clr_top};
                      return bo(Blue_0, o, 0, &(Quattro){&r, q->Green, q->Yellow, q->Red}, s, u); }

Chapter S(Yellow_0) { return Green_0(q->Blue->partition, o, t, q, s, u); }
Chapter S(Yellow_1) { return Yellow_0(C, u); }
Chapter S(Yellow_2) { return Green_2(C, u); }
Chapter S(Yellow_3) { if (q->Blue->clr(C, u)) return 0;
                      Ray r = { .upper = q,
                                .t = t,
                                .partition = b,
                                .new_partition = Yellow_0,
                                .continue_or_return_to_next = cont,
                                .clr = clr};
                      return bo(Blue_0, o, 0, &(Quattro){&r, q->Green, q->Yellow, q->Red}, s, u); }

Chapter S(Red_0   ) { return 0; }
Chapter S(Red_1   ) { return 0; }
Chapter S(Red_2   ) { return 0; }
Chapter S(Red_3   ) { int rez = q->Blue->clr(C, u);
                      if (rez == 2) return 0;
                      if (rez == 1) return bo(Green_0, o, t + 2, q, s, u);
                      Ray r = { .upper = q,
                                .t = t,
                                .partition = q->Blue->upper->Blue->partition,
                                .new_partition = Red_0,
                                .continue_or_return_to_next = cont,
                                .clr = clr};
                      return bo(Blue_0, o, 0, &(Quattro){&r, q->Green, q->Yellow, q->Red}, s, u); }


static long ram[2048];
S(ret) { return 0; }
#include <assert.h>
S(ok      ) { return bo(Green_0, o, t+2, q, s, u); }

S(term_t  ) { return ok(C, (long[]){"t", u}); }
S(term_a  ) { return ok(C, (long[]){"a", u}); }
S(term_b  ) { return ok(C, (long[]){"b", u}); }
S(term_o  ) { return ok(C, (long[]){"o", u}); }
S(term_1  ) { return ok(C, (long[]){"1", u}); }
S(term_2  ) { return ok(C, (long[]){"2", u}); }
S(term_3  ) { return ok(C, (long[]){"3", u}); }
S(term_nl ) {
  const char*strs[100];
  int len = 0;
  void**l = (void*)u;
  while(l) strs[len++] = l[0], l = l[1];
  while(len) printf("%s", strs[--len]);
  printf("\n");
  return bo(Green_0, o,t+2,q,s, u); }
int main() {
  long *o = ram + 1024;
  long s = 0;
  long t = s;
  long u = 0;

  // partition-supported programming through linker script
  // partition operator?
  assert((Red_0 - Blue_0) / ChapterSize / 4 == 3);

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = term_##b
#define T(S) o[s++] = 3, o[s++] = S

  D('_'), T('3'), B(nl);
  D('3'), T('T'), T('T'), T('T');
  D('T'), B(t);
  D('T'), B(a);
  D('T'), B(b), T('N');
  D('N'), B(1);
  D('N'), B(2);
  D('N'), B(3);

  D('s'), T('s');

  D('S'), B(b);
  D('S'), T('S'), B(a);
  D('S'), T('S'), B(t), T('O');
  D('O');
  D('O'), B(o);

  D('A'), B(b);
  D('A'), T('B'), B(a);
  D('B'), B(t);
  D('B'), T('A'), B(o);

  o[s++] = 0;
  o[s++] = 0;

  Ray r = {
    .upper = 0,
    .t = 0,
    .partition = Yellow_0,
    .new_partition = Yellow_0,
    .continue_or_return_to_next = ret,
    .clr = clr_top
  };
  bo(Blue_0, o, 0, &(Quattro){&r, 0, 0, 0}, s, u);
  return 0;
}
/*
primary_expression:
  constant
  (expression)

unary-expression:
  primary-expression
  unary_operator unary_expression
unary_operator: one of
  & * + - ~ !


multiplicative_expression:
  unary_expression
  multiplicative_expression * unary_expression
  multiplicative_expression / unary_expression
  multiplicative_expression % unary_expression

additive_expression:
  multiplicative_expression
  additive_expression + multiplicative_expression
  additive_expression - multiplicative_expression

expression:
  additive_expression
            */
