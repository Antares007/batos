#include "common.h"

#include "bo_id.h"
#include <stdio.h>
// clang-format off
S(Zero  ) { printf("zero\n");                     id_0(Args); } 
S(One   ) { printf("{1} ");                       id_1(Args); } 
S(Two   ) { printf("%s ", (char *)o[t]),          id_2(Args); } 
S(Three ) { printf("\n"),                         id_3(Args); } 
S(Four  ) { printf("%s ", (char *)o[t]),          id_4(Args); } 
S(Five  ) { printf("."),                          id_5(Args); } 
S(Six   ) { printf("{6} "),                       id_6(Args); } 
S(Seven ) { printf(" "),                          id_7(Args); } 
S(Eight ) { printf("...\n"), t = o[t],            id_8(Args); } 

#define C(I) Chapter(I) N(book_of_print_##I)
C(0) { Zero  (Args); }
C(1) { One   (Args); }
C(2) { Two   (Args); }
C(3) { Three (Args); }
C(4) { Four  (Args); }
C(5) { Five  (Args); }
C(6) { Six   (Args); }
C(7) { Seven (Args); }
C(8) { Eight (Args); }
