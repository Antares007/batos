#define C(I) Chapter(I) N(id_##I)
#include "common.h"

__attribute__((noinline)) N(bo) {
  n_t chapter = (((n_t)o[b]) + ChapterSize * (long)o[t]);
  t++;
  chapter(Args);
}

C(0) { b++, bo(Args); }
C(1) { t += 4, bo(Args); }
C(2) { t++, bo(Args); }
C(3) { bo(Args); }
C(4) { t++, bo(Args); }
C(5) { bo(Args); }
C(6) { t++, bo(Args); }
C(7) { bo(Args); }
C(8) { t = o[t], bo(Args); }
