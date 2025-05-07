#include "common.h"

// clang-format off
S((*Print_nars[]));
N(Print_book) { Print_nars[o[t]](b,a,t+1,o,s);}
S(zero      ) { printf("");}
S(one       ) { printf("{1} ");              Print_book(b, a, t, o, s); }
S(two       ) { printf("%s ", (char*)o[t++]);Print_book(b, a, t, o, s); }
S(three     ) { printf("\n");                Print_book(b, a, t, o, s); }
S(four      ) { printf("%s ", (char*)o[t++]);Print_book(b, a, t, o, s); }
S(five      ) { printf(".");                 Print_book(b, a, t, o, s); }
S(six       ) { printf("{6} "); t++,         Print_book(b, a, t, o, s); }
S(seven     ) { printf(" ");                 Print_book(b, a, t, o, s); }
S((*Print_nars[])) = {
    zero, one, two, three, four, five, six, seven
};

S((*Green_nars[]));
N(Green_book) { Green_nars[o[t]](b,a,t+1,o,s);}
S(Green_0) {P;}
S(Green_1) {P; o[--b] = Green_book; ((n_t)o[t])(b,a,t+1,o,s); }
S(Green_2) {P;}
S(Green_3) {P;}
S(Green_4) {P;}
S(Green_5) {P;}
S(Green_6) {P;}
S(Green_7) {P;}
S((*Green_nars[])) = { Green_0, Green_1, Green_2, Green_3, Green_4, Green_5, Green_6, Green_7 };

S((*defoff_nars[]));
N(defoff_book) { defoff_nars[o[t]](b,a,t+1,o,s);}
S(defoff_0) { P;
  for(long n = o[Blue]; n < s; n++) {
    long match = 0;
    for(long d = b; d < o[Red]; d++)
    {
      if(o[o[d]] == o[o[n]])
        //printf("%s %ld %ld %ld\n", (char*)o[o[d]], o[n], o[d], o[d] - 1 - o[n]), 
          match++;
    }
    if(match!=1) printf("!!!error\n");
  }
  s = o[Blue];
  b = o[Red];
  o[Red] = o[b++];
  o[Blue] = o[b++];
}
S(defoff_1) {
  o[--b] = o[Blue];
  o[--b] = o[Red];
  o[Red ] = b;
  o[Blue] = s; 
  defoff_book(b,a,t,o,s);
}
S(defoff_2) {  o[s++] = t,   t++, defoff_book(b,a,t,o,s); }
S(defoff_3) {                     defoff_book(b,a,t,o,s); }
S(defoff_4) {  o[--b] = t,   t++, defoff_book(b,a,t,o,s); }
S(defoff_5) {                     defoff_book(b,a,t,o,s); }
S(defoff_6) {                t++, defoff_book(b,a,t,o,s); }
S(defoff_7) {                     defoff_book(b,a,t,o,s); }
S((*defoff_nars[])) = { defoff_0, defoff_1, defoff_2, defoff_3, defoff_4, defoff_5, defoff_6, defoff_7 };


/*
Os
  S.
S
  Os.
  'b'.
  S 'a'.

*/
