#include "common.h"

N(ob) { ((n_t **)o)[b][o[t]](o, b, a, t + 1, s, r); }

// clang-format off
N((*Print_nars[]));


S(zero      ) { printf("zero\n"); }
S(one       ) { printf("{1} "); t += 4,      ob(o, b, a, t, s, r); }
S(two       ) { printf("%s ", (char*)o[t++]);ob(o, b, a, t, s, r); }
S(three     ) { printf("\n");                ob(o, b, a, t, s, r); }
S(four      ) { printf("%s ", (char*)o[t++]);ob(o, b, a, t, s, r); }
S(five      ) { printf(".");                 ob(o, b, a, t, s, r); }
S(six       ) { printf("{6} "); t++,         ob(o, b, a, t, s, r); }
S(seven     ) { printf(" ");                 ob(o, b, a, t, s, r); }
S(eight     ) { printf("...\n");             ob(o, b, a, o[t], s, r); }
N((*Print_nars[])) = {
    zero, one, two, three, four, five, six, seven, eight
};

S((*Green_nars[]));
N(Green_book) { Green_nars[o[t]](o,b,a,t+1,s,r);}
S(Green_0) {P;}
S(Green_1) {P; o[--b] = Green_book; ((n_t)o[t])(o,b,a,t+1,s,r); }
S(Green_2) {P;}
S(Green_3) {P;}
S(Green_4) {P;}
S(Green_5) {P;}
S(Green_6) {P;}
S(Green_7) {P;}
S((*Green_nars[])) = { Green_0, Green_1, Green_2, Green_3, Green_4, Green_5, Green_6, Green_7 };

S((*finddef_nars[]));
S(finddef_0) { P; }
S(finddef_1) { t += 4,     ob(o,b,a,t,s,r); }
S(finddef_2) { t++,        ob(o,b,a,t,s,r); }
S(finddef_3) {             ob(o,b,a,t,s,r); }
#include<string.h>
S(finddef_4 ) { P; 
                if(strcmp(o[t],o[o[b+1]]) == 0)
                  printf("%s %s %ld\n", (char*)o[t], (char*)o[o[b+1]], t-1 - o[b+1]),
                       ob(o,b+2,a,o[b+1]+1,s,r);
                else
                  t++, ob(o,b,a,t,s,r);
}
S(finddef_5) {            ob(o,b,a,t,s,r); }
S(finddef_6) { t++,       ob(o,b,a,t,s,r); }
S(finddef_7) {            ob(o,b,a,t,s,r); }
S(finddef_8) {            ob(o,b,a,o[t],s,r); }
S((*finddef_nars[])) = { finddef_0, finddef_1, finddef_2, finddef_3, finddef_4, finddef_5, finddef_6, finddef_7, finddef_8 };

N((*defoff_nars[]));
S(defoff_0) { P;b++,  ob(o,b,a,t,s,r); }
S(defoff_1) { P;t+=4, ob(o,b,a,t,s,r); }
S(defoff_2) { P;
              o[--b] = t,
              o[--b] = finddef_nars, 
              ob(o,b,a,r[Blue],s,r);
}
S(defoff_3) { P;             ob(o,b,a,t,s,r); }
S(defoff_4) { P; t++,        ob(o,b,a,t,s,r); }
S(defoff_5) { P;             ob(o,b,a,t,s,r); }
S(defoff_6) { P; t++,        ob(o,b,a,t,s,r); }
S(defoff_7) { P;             ob(o,b,a,t,s,r); }
S(defoff_8) { P;             ob(o,b,a,o[t],s,r); }
N((*defoff_nars[])) = { defoff_0, defoff_1, defoff_2, defoff_3, defoff_4, defoff_5, defoff_6, defoff_7, defoff_8 };


/*
Os
  S.
S
  Os.
  'b'.
  S 'a'.

*/
