// clang-format off
#include "common.h"
#include <stdio.h>

#include "book.h"
#define ChapterSize 128

__attribute__((noinline)) N(bo) {
  n_t chapter = (((n_t)o[b]) + ChapterSize * (long)o[t]);
  t++;
  chapter(Args);
}

// clang-format off
Chapter N(id_0) { b++, bo(Args); }
Chapter N(id_1) {      bo(Args); }
Chapter N(id_2) { t++, bo(Args); }
Chapter N(id_3) {      bo(Args); }
Chapter N(id_4) { t++, bo(Args); }
Chapter N(id_5) {      bo(Args); }
Chapter N(id_6) { t++, bo(Args); }

Chapter __attribute__((noinline))  N(bp_0) { printf("zero\n"),             id_0(Args); }
Chapter __attribute__((noinline))  N(bp_1) { printf("{1} "),               id_1(Args); }
Chapter __attribute__((noinline))  N(bp_2) { printf("%s ", (char *)o[t]),  id_2(Args); }
Chapter __attribute__((noinline))  N(bp_3) { printf("\n"),                 id_3(Args); }
Chapter __attribute__((noinline))  N(bp_4) { printf("%s ", (char *)o[t]),  id_4(Args); }
Chapter __attribute__((noinline))  N(bp_5) { printf("."),                  id_5(Args); }
Chapter __attribute__((noinline))  N(bp_6) { printf("'%s' ", (char *)o[t]),id_6(Args); }


#include <string.h>

S(match) {
  if (strcmp(o[t], o[o[b + 1]]) == 0)
    printf("\b%s %s %ld\n", (char *)o[t], (char *)o[o[b + 1]],
           t - 1 - o[b + 1]),
        t = o[b + 1] + 1, b = b + 2, bo(Args);
  else
    t++, bo(Args);
}
Chapter N(finddef_0) { bp_0(Args); }
Chapter N(finddef_1) { bp_1(Args); }
Chapter N(finddef_2) { bp_2(Args); }
Chapter N(finddef_3) { bp_3(Args); }
Chapter N(finddef_4) { match(Args); }
Chapter N(finddef_5) { bp_5(Args); }
Chapter N(finddef_6) { bp_6(Args); }

Chapter N(defoff_0) { bp_0(Args); }
Chapter N(defoff_1) { bp_1(Args); }
Chapter N(defoff_2) { t = 0, finddef_0(Args); }
Chapter N(defoff_3) { bp_3(Args); }
Chapter N(defoff_4) { bp_4(Args); }
Chapter N(defoff_5) { bp_5(Args); }
Chapter N(defoff_6) { bp_6(Args); }

/*
S
  'b'.
  S 'a'.
  S 't'. 'o'.

*/
