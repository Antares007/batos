// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"

#define _STR(s) #s
#define STR(s) _STR(s)
#define Chapter                                                                \
  __attribute__((section("." __FILE_NAME__ STR(__LINE__))))                    \
  __attribute__((__noinline__))
#ifndef ChapterSize
#define ChapterSize 512
#endif

#define P (void)0 // printf("%s\n", __func__)
// #define P printf("%2ld %10s %c\n", t, __func__, (char)o[t+1])

#include <stdio.h>
#define Context long *o, long t, struct Tword *tword, long s
#define N(argo) long argo(Context)
#define C o, t, tword, s
typedef struct Tword {
  struct Tword*upper;
  long t;
  N((*right));
  N((*clr));
} Tword;
typedef N((*n_t));
static inline long book_of(n_t book, Context) {
  return (book + o[t] * ChapterSize)(C);
}

N(Blue_0);
N(Green_0);

// int clr_top(Context) { return b[3] == o[t]; }
// int clr(Context) {
//  //if (b[3] == o[t]) {
//  //} else {
//  //  long ut = ((n_t)b[5])(o,t,b[0]);
//  //  return t;
//  //}
//}

Chapter N(Green_0 ) { return tword->right(C); }
Chapter N(Green_1 ) { return tword->right(C); }
Chapter N(Green_2 ) { return printf("%c", (char)o[t + 1]), book_of(Green_0, o, t + 2, tword, s); }
        N(cont    ) { return book_of(Green_0, o, tword->t + 2, tword->upper, s); }
Chapter N(Green_3 ) { return book_of(Blue_0, o, 0, &(Tword){.upper = tword, .t = t, .right = cont, .clr = 0}, s); }

Chapter N(Yellow_0) { return tword->right(C); }
Chapter N(Yellow_1) { return tword->right(C); }
Chapter N(Yellow_2) { return printf("%c", (char)o[t + 1]), book_of(Green_0, o, t + 2, tword, s); }
Chapter N(Yellow_3) { return book_of(Blue_0, o, 0, &(Tword){.upper = tword, .t = t, .right = cont, .clr = 0}, s); }

Chapter N(Blue_0  ) { o[s+t] = o[t] + 4, o[s+t+1] = o[t+1] + 4; return s + t; }
Chapter N(Blue_1  ) { if (o[tword->t + 1] == o[t + 1])
                        book_of(Yellow_0, o, t + 2, tword, s);
                      book_of(Blue_0, o, t + 2, tword, s);
                      return t;
                    }
Chapter N(Blue_2  ) { return book_of(Blue_0, o, t + 2, tword, s); }
Chapter N(Blue_3  ) { return book_of(Blue_0, o, t + 2, tword, s); }


static long ram[2048];
N(ret) { return printf("\n"), t; }
int main() {
  long *o = ram + 1024;
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S
  D('.'), T('3');                 // . -> 3 - argumented grammar rule
                                  //
  D('S'), B('b');                 // S -> 'b'
  D('S'), T('S'), B('a');         // S -> S 'a'
                                  //
  D('A'), B('a');                 // A -> 'a'
  D('A'), T('B'), B('a');         // A -> B 'a'
  D('B'), B('b');                 // B -> 'b'
  D('B'), T('A'), B('b');         // B -> A 'b'
                                  //
  D('3'), T('T'), T('T'), T('T'); // 3 -> T T T '\n'
  D('T'), B('t');                 // T -> 't'
  D('T'), B('a');                 // T -> 'a'
  D('T'), B('b');                 // T -> 'b'

  o[s++] = 0;
  o[s++] = 0;
  book_of(Blue_0, o, 0, &(Tword){.upper = 0, .t = 0, .right = ret, .clr = 0}, s);
}
