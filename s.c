// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"

#include "book.h"
#define ChapterSize 512

#include <stdio.h>
#include <stdarg.h>
extern int usleep (__useconds_t __useconds);
static long indent = 0;
void iprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    for(long i = 0; i < indent; i++) printf(" ");
    vprintf(format, args);
    va_end(args);
}
#include <stdio.h>
#define Context void*b, long *o, long t, struct Tword *tword, long s, long*u
#define N(argo) long argo(Context)
#define C b, o, t, tword, s
typedef struct Tword {
  struct Tword*upper;
  long t;
  N((*partition));
  N((*new_partition));
  N((*continue_or_return_to_next));
  N((*clr));
} Tword;
typedef N((*n_t));
#define S(argo) static N(argo)

S(Blue_0); S(Green_0); S(Yellow_0); S(Red_0);
S(bo) { return (((n_t)b) + o[t] * ChapterSize)(C, u); }

Chapter S(Blue_0  ) { return t; }
Chapter S(Blue_1  ) { Tword*p = tword; int depth = 0; while(p) p = p->upper, depth++;
                      if (5 < depth) return t;
                      if (o[tword->t + 1] == o[t + 1]) bo(tword->new_partition, o, t + 2, tword, s, u);
                      return bo(b, o, t + 2, tword, s, u); }
Chapter S(Blue_2  ) { return bo(b, o, t + 2, tword, s, u); }
Chapter S(Blue_3  ) { return bo(b, o, t + 2, tword, s, u); }


S(clr_top         ) { return o[tword->t + 1] == o[t + 1]; }
S(clr             ) { return o[tword->t + 1] == o[t + 1] ? 2 : tword->upper->clr(b, o, t, tword->upper, s, u); }
S(cont            ) { return bo(b, o, tword->t + 2, tword->upper, s, u); }
S(upper_cont      ) { return tword->upper->continue_or_return_to_next(b, o, t, tword->upper, s, u); }

Chapter S(Green_0 ) { return tword->continue_or_return_to_next(C, u),
                             bo(Blue_0, o, 0, &(Tword){ .upper = tword,
                                                        .t = tword->t,
                                                        .partition = b,
                                                        .new_partition = Red_0,
                                                        .continue_or_return_to_next = upper_cont,
                                                        .clr = clr_top }, s, u); }
Chapter S(Green_1 ) { return Green_0(C, u); }
Chapter S(Green_2 ) { return ((n_t)o[t + 1])(C, u); }
Chapter S(Green_3 ) { return bo(Blue_0, o, 0, &(Tword){ .upper = tword,
                                                        .t = t,
                                                        .partition = b,
                                                        .new_partition = Yellow_0,
                                                        .continue_or_return_to_next = cont,
                                                        .clr = clr_top }, s, u); }

Chapter S(Yellow_0) { return Green_0(tword->partition, o, t, tword, s, u); }
Chapter S(Yellow_1) { return Yellow_0(C, u); }
Chapter S(Yellow_2) { return Green_2(C, u); }
Chapter S(Yellow_3) { if (tword->clr(C, u)) return 0;
                      return bo(Blue_0, o, 0, &(Tword){ .upper = tword,
                                                        .t = t,
                                                        .partition = b,
                                                        .new_partition = Yellow_0,
                                                        .continue_or_return_to_next = cont,
                                                        .clr = clr}, s, u); }

Chapter S(Red_0   ) { return 0; }
Chapter S(Red_1   ) { return 0; }
Chapter S(Red_2   ) { return 0; }
Chapter S(Red_3   ) { int rez = tword->clr(C, u);
                      if (rez == 2) return 0;
                      if (rez == 1) return bo(Green_0, o, t + 2, tword, s, u);
                      return bo(Blue_0, o, 0, &(Tword){ .upper = tword,
                                                        .t = t,
                                                        .partition = tword->upper->partition,
                                                        .new_partition = Red_0,
                                                        .continue_or_return_to_next = cont,
                                                        .clr = clr}, s, u); }


static long ram[2048];
N(ret) { return 0; }
#include <assert.h>
N(ok      ) { return bo(Green_0, o, t+2, tword, s, u); }

N(term_t  ) { return ok(C, (long[]){"t", u}); }
N(term_a  ) { return ok(C, (long[]){"a", u}); }
N(term_b  ) { return ok(C, (long[]){"b", u}); }
N(term_o  ) { return ok(C, (long[]){"o", u}); }
N(term_s  ) { return ok(C, (long[]){"s", u}); }
N(term_1  ) { return ok(C, (long[]){"1", u}); }
N(term_2  ) { return ok(C, (long[]){"2", u}); }
N(term_3  ) { return ok(C, (long[]){"3", u}); }
N(term_nl ) {
  const char*strs[100];
  int len = 0;
  void**l = (void*)u;
  while(l) strs[len++] = l[0], l = l[1];
  while(len) printf("%s", strs[--len]);
  printf("\n");
  return bo(Green_0, o,t+2,tword,s, u); }
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

  D('_'), T('s'), B(nl);
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
  //D('D');
  //D('D'), B('d');
  //
  D('A'), B(b);
  D('A'), T('B'), B(a);
  D('B'), B(t);
  D('B'), T('A'), B(o);
  //
  //D('2'), T('T'), T('T');
  //D('1'), T('T');
  o[s++] = 0;
  o[s++] = 0;
  Tword tword = {
    .upper = 0,
    .t = 0,
    .partition = Yellow_0,
    .new_partition = Yellow_0,
    .continue_or_return_to_next = ret,
    .clr = clr_top
  };
  bo(Blue_0, o, 0, (&tword), s, u);
}
