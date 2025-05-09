#include "common.h"
#define C(I) Chapter(I) N(defoff_##I)

N(finddef_0);

#include "bo_id.h"

S(search) { o[--b] = t, o[--b] = finddef_0, t = r[Blue], bo(Args); }
C(0) { id_0(Args); }
C(1) { id_1(Args); }
C(2) { search(Args); }
C(3) { id_3(Args); }
C(4) { id_4(Args); }
C(5) { id_5(Args); }
C(6) { id_6(Args); }
C(7) { id_7(Args); }
C(8) { id_8(Args); }
