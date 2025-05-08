#include "common.h"

N(bo) {
  n_t chapter = (((n_t)o[b]) + ChapterSize * (long)o[t]);
  t++;
  chapter(Args);
}

#include <stdio.h>
// clang-format off
S(Zero  ) { printf("zero\n");                                 } 
S(One   ) { printf("{1} ");                 t += 4; bo(Args); } 
S(Two   ) { printf("%s ", (char *)o[t++]),          bo(Args); } 
S(Three ) { printf("\n"),                           bo(Args); } 
S(Four  ) { printf("%s ", (char *)o[t++]),          bo(Args); } 
S(Five  ) { printf("."),                            bo(Args); } 
S(Six   ) { printf("{6} "), t++,                    bo(Args); } 
S(Seven ) { printf(" "),                            bo(Args); } 
S(Eight ) { printf("...\n"), t = o[t],              bo(Args); } 

Chapter(0)N(book_of_print) { Zero  (Args); }
Chapter(1)S(one          ) { One   (Args); }
Chapter(2)S(two          ) { Two   (Args); }
Chapter(3)S(three        ) { Three (Args); }
Chapter(4)S(four         ) { Four  (Args); }
Chapter(5)S(five         ) { Five  (Args); }
Chapter(6)S(six          ) { Six   (Args); }
Chapter(7)S(seven        ) { Seven (Args); }
Chapter(8)S(eight        ) { Eight (Args); }
