#include "common.h"
#include <string.h>
// clang-format off
N(bo);
Chapter( 0)S(finddef_0) { P; }
Chapter( 1)S(finddef_1) { t += 4,   bo(Args); }
Chapter( 2)S(finddef_2) { t++,      bo(Args); }
Chapter( 3)S(finddef_3) {           bo(Args); }
Chapter( 4)D(finddef_4) { if(strcmp(o[t], o[o[b + 1]]) == 0)
                            printf("%s %s %ld\n", (char*)o[t], (char*)o[o[b+1]], t-1 - o[b+1]),
                            t = o[b + 1] + 1, b = b + 2, bo(Args);
                          else
                            t++, bo(Args); }
Chapter( 5)S(finddef_5) {           bo(Args); }
Chapter( 6)S(finddef_6) { t++,      bo(Args); }
Chapter( 7)S(finddef_7) {           bo(Args); }
Chapter( 8)S(finddef_8) { t = o[t], bo(Args); }

Chapter( 9)N(defoff_0 ) { b++, t=r[Blue],     bo(Args); }
Chapter(10)S(defoff_1 ) { t += 4,   bo(Args); }
Chapter(11)D(defoff_2 ) { o[--b] = t,
                          o[--b] = finddef_0, 
                          t = r[Blue], bo(Args); }
Chapter(12)S(defoff_3 ) {           bo(Args); }
Chapter(13)S(defoff_4 ) { t++,      bo(Args); }
Chapter(14)S(defoff_5 ) {           bo(Args); }
Chapter(15)S(defoff_6 ) { t++,      bo(Args); }
Chapter(16)S(defoff_7 ) {           bo(Args); }
Chapter(17)S(defoff_8 ) { t = o[t], bo(Args); }
/*
Os
  S.
S
  Os.
  'b'.
  S 'a'.

*/
