// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"

#include "book.h"
#define ChapterSize 256

// #define P (void)0 // printf("%s\n", __func__)
#define P printf("%2ld %10s %c\n", t, __func__, (char)o[t+1])

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
#define book_of(BOOK, O, T, TWORD, S) ((BOOK + O[T] * ChapterSize)(O, T, TWORD, S))

N(Blue_0);
N(Green_0);

N(clr_top) { return o[tword->t + 1] == o[t + 1]; }
N(clr) {
  if (o[tword->t + 1] == o[t + 1]) {
    return 1;
  } else {
    return tword->upper->clr(o, t, tword->upper, s);
  }
}

Chapter N(Green_0 ) {P; return tword->right(C); }
Chapter N(Green_1 ) {P; return tword->right(C); }
Chapter N(Green_2 ) {P; return book_of(Green_0, o, t + 2, tword, s); }
        N(cont    ) {P; return book_of(Green_0, o, tword->t + 2, tword->upper, s); }
Chapter N(Green_3 ) {P; return book_of(Blue_0, o, 0, (&(Tword){.upper = tword, .t = t, .right = cont, .clr = clr}), s); }

Chapter N(Yellow_0) {P; return tword->right(C); }
Chapter N(Yellow_1) {P; return tword->right(C); }
Chapter N(Yellow_2) {P; return book_of(Green_0, o, t + 2, tword, s); }
Chapter N(Yellow_3) {P; //long rez = tword->clr(C);
                        //if (rez)
                        //  return book_of(Green_0, o, t + 2, tword, s);
                        return book_of(Blue_0, o, 0, (&(Tword){.upper = tword, .t = t, .right = cont, .clr = clr}), s); }

Chapter N(Blue_0  ) {P; return t; }
Chapter N(Blue_1  ) {P; if (o[tword->t + 1] == o[t + 1])
                          book_of(Yellow_0, o, t + 2, tword, s);
                        return book_of(Blue_0, o, t + 2, tword, s); }
Chapter N(Blue_2  ) {P; return book_of(Blue_0, o, t + 2, tword, s); }
Chapter N(Blue_3  ) {P; return book_of(Blue_0, o, t + 2, tword, s); }

static long ram[2048];
N(ret) {P; return t; }
int main() {
  long *o = ram + 1024;
  long s = 0;
  long t = s;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S
  D('3'), T('T'), T('T'), T('T'); // 3 -> T T T
  D('T'), B('t');                 // T -> 't'
  D('T'), B('a');                 // T -> 'a'
  D('T'), B('b');                 // T -> 'b'
                                  //
  //D('.'), T('3'), B('.');         // . -> 3 - argumented grammar rule
  //                                //
  //D('S'), B('b');                 // S -> 'b'
  //D('S'), T('S'), B('a');         // S -> S 'a'
  //                                //
  //D('A'), B('0');                 // A -> 'a'
  //D('A'), T('B'), B('1');         // A -> B 'a'
  //D('B'), B('2');                 // B -> 'b'
  //D('B'), T('A'), B('3');         // B -> A 'b'
  //                                //
  //D('2'), T('T'), T('T');         // 2 -> T
  //D('1'), T('T');                 // 1 -> T

  o[s++] = 0;
  o[s++] = 0;
  Tword tword = {.upper = 0, .t = 0, .right = ret, .clr = clr_top};
  book_of(Blue_0, o, 0, (&tword), s);
}
