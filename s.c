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

#include <stdio.h>

#define N(argo) void argo(long b, long *o, long t, long *Blue)
typedef N((*n_t));

Chapter N(Green_) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Greenδ) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Greenβ) {
  P, printf("%c", (char)o[t + 1]), (Green_ + o[t + 2] * CS)(b, o, t + 2, Blue);
}
N(cont) {
  P;
  t = Blue[6];
  Blue = Blue[0];
  (Green_ + o[t + 2] * CS)(b, o, t + 2, Blue);
}
N(Blue_);
Chapter N(Greenτ) {
  P;
  long Blue2[] = {Blue, 0, 0, 0, o[t + 1], cont, t};
  (Blue_ + o[0] * CS)(b, o, 0, Blue2);
}

Chapter N(Yellow_) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Yellowδ) { P, ((n_t)Blue[5])(b, o, t, Blue); }
Chapter N(Yellowβ) {
  P;
  printf("%c", (char)o[t + 1]), (Green_ + o[t + 2] * CS)(b, o, t + 2, Blue);
}
Chapter N(Yellowτ) {
  P;
  long Blue2[] = {Blue, 0, 0, 0, o[t + 1], cont, t};
  (Blue_ + o[0] * CS)(b, o, 0, Blue2);
}

Chapter N(Blue_) {
  P;
  ((n_t)Blue[5])(b, o, t, Blue);
}
Chapter N(Blueδ) {
  P;
  if (Blue[4] == o[t + 1])
    (Yellow_ + o[t + 2] * CS)(b, o, t + 2, Blue);
  (Blue_ + o[t + 2] * CS)(b, o, t + 2, Blue);
}
Chapter N(Blueβ) { (Blue_ + o[t + 2] * CS)(b, o, t + 2, Blue); }
Chapter N(Blueτ) { (Blue_ + o[t + 2] * CS)(b, o, t + 2, Blue); }

N(capstone) { P; }

static long ram[2048];
N(ret) { P; }
int main() {
  long *o = ram + 1024;
  long b = 0;
  long t = 0;
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S

  D('S'), B('b');                          // S -> 'b'
  D('S'), T('S'), B('a');                  // S -> S 'a'
                                           //
  D('A'), B('a');                          // A -> 'a'
  D('A'), T('B'), B('a');                  // A -> B 'a'
  D('B'), B('b');                          // B -> 'b'
  D('B'), T('O'), B('b');                  // B -> A 'b'
                                           //
  D('3'), T('T'), T('T'), T('T'), B('\n'); // 3 -> T T T '\n'
  D('T'), B('t');                          // T -> 't'
  D('T'), B('a');                          // T -> 'a'
  D('T'), B('b');                          // T -> 'b'

  o[s++] = 0;
  long cap[] = {0, 0, 0, 0, capstone};
  long Blue[] = {cap, cap, cap, cap, '3', ret};
  (Blue_ + o[t] * CS)(b, o, t, Blue);
}
