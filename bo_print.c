#include "common.h"

#include "bo_id.h"
#include <stdio.h>
// clang-format off

#define C(I) Chapter(I) N(book_of_print_##I)
C(0) { printf("zero\n");             id_0(Args); }
C(1) { printf("{1} ");               id_1(Args); }
C(2) { printf("%s ", (char *)o[t]),  id_2(Args); }
C(3) { printf("\n"),                 id_3(Args); }
C(4) { printf("%s ", (char *)o[t]),  id_4(Args); }
C(5) { printf("."),                  id_5(Args); }
C(6) { printf("{6} "),               id_6(Args); }
C(7) { printf(" "),                  id_7(Args); }
C(8) { printf("...\n"),              id_8(Args); }
