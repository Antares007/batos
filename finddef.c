#define C(I) Chapter(I) N(finddef_##I)

#include "common.h"
#include <string.h>

S(match) {
  if (strcmp(o[t], o[o[b + 1]]) == 0)
    printf("%s %s %ld\n", (char *)o[t], (char *)o[o[b + 1]], t - 1 - o[b + 1]),
        t = o[b + 1] + 1, b = b + 2, bo(Args);
  else
    t++, bo(Args);
}

#include "bo_id.h"
C(0) { id_0(Args); }
C(1) { id_1(Args); }
C(2) { id_2(Args); }
C(3) { id_3(Args); }
C(4) { match(Args); }
C(5) { id_5(Args); }
C(6) { id_6(Args); }
C(7) { id_7(Args); }
C(8) { id_8(Args); }

/*
Os
  S.
S
  Os.
  'b'.
  S 'a'.

*/
