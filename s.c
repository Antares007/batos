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
#define CS ChapterSize

#define P (void)0 // printf("%s\n", __func__)
// #define P printf("%2ld %10s %c\n", t, __func__, (char)o[t+1])

#include <stdio.h>

#define N(argo) void argo(void*b, long *o, long t, long *Blue)
typedef N((*n_t));

// Chapter N(Green_) { P, ((n_t)Blue[5])(b, o, t, Blue); }
// Chapter N(Green_D) { P, ((n_t)Blue[5])(b, o, t, Blue); }
// Chapter N(Green_B) { P; printf("2%c", (char)o[t + 1]), (Green_ + o[t + 2] *
// CS)(b, o, t + 2, Blue); } Chapter N(Green_T) { P; long Blue2[] = {Blue, 0, 0,
// 0, o[t + 1], cont, t}; (Blue_ + o[0] * CS)(b, o, 0, Blue2); }
//
static N(bo) {(((n_t)b) + o[t] * ChapterSize)(b, o, t, Blue);}

N(Blue_);
N(Yellow_);
N(cont) {
  P;
  t = Blue[6];
  Blue = Blue[0];
  (Yellow_ + o[t + 2] * CS)(b, o, t + 2, Blue);
}
Chapter N(Yellow_) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Yellow_D) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Yellow_B) { P; printf("%c", (char)o[t+1]), bo(Yellow_, o, t + 2, Blue); }
Chapter N(Yellow_T) { P, bo(Blue_, o, 0, (long[]){Blue, 0, 0, 0, o[t + 1], cont, t}); }
Chapter N(Blue_   ) { P;  }
Chapter N(Blue_D  ) { P;
                      if (Blue[4] == o[t + 1])
                        bo(Yellow_, o, t + 2, Blue);
                      bo(b, o, t + 2, Blue); }
Chapter N(Blue_B  ) { bo(b, o, t + 2, Blue); }
Chapter N(Blue_T  ) { bo(b, o, t + 2, Blue); }

N(capstone) { P; }

static long ram[2048];
N(ret) {
  P;
//  char buff[1024];
//  int len = 0;
//  while(b)
//    buff[len++] = *b, b = b[1];
//  while(len--) 
//    printf("%c", buff[len]);
  printf("\n");
}
int main() {
  long *o = ram + 1024;
  long b = 0;
  long t = 0;
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S

  D('S'), B('b');         // S -> 'b'
  D('S'), T('S'), B('a'); // S -> S 'a'
                          //
  D('A'), B('a');         // A -> 'a'
  D('A'), T('B'), B('a'); // A -> B 'a'
  D('B'), B('b');         // B -> 'b'
  D('B'), T('O'), B('b'); // B -> A 'b'
                          //
  D('3'), T('T'), T('T'), T('T'); // 3 -> T T T '\n'
  D('T'), B('t');         // T -> 't'
  D('T'), B('a');         // T -> 'a'
  D('T'), B('b');         // T -> 'b'

  o[s++] = 0;
  long cap[] = {0, 0, 0, 0, capstone};
  bo(Blue_, o, t, (long[]){cap, cap, cap, cap, '3', ret});
}
