#define C(I) Chapter(I) N(id_##I)
#include "common.h"

__attribute__((noinline)) N(bo) {
  n_t chapter = (((n_t)o[b]) + ChapterSize * (long)o[t]);
  t++;
  chapter(Args);
}
S(restore_quattro_registers) {
  r[Blue] = o[t++], r[Green] = o[t++], r[Yellow] = o[t++], r[Green] = o[t++],
  bo(Args);
}
C(0) { b++, bo(Args); }
C(1) { restore_quattro_registers(Args); }
C(2) { t++, bo(Args); }
C(3) { bo(Args); }
C(4) { t++, bo(Args); }
C(5) { bo(Args); }
C(6) { t++, bo(Args); }
C(7) { bo(Args); }
C(8) { t = r[o[t]], bo(Args); }
