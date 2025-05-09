#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"

#define N(argo)                                                                \
  void argo(long *o, long b, long a, long t, long s, long *__restrict r)
#define Args o, b, a, t, s, r

typedef N((*n_t));
typedef enum { Maroon, Olive, Lime, Navy, Blue, Green, Yellow, Red } Colors;

#ifndef NDEBUG
#include <stdio.h>
#define P printf("%s\n", __func__)
#else
#define P 0
#endif

#define S(argo) __attribute__((noinline)) static N(argo)

#define Chapter(N) __attribute__((section("." __FILE_NAME__ #N)))
#define D(argo)                                                                \
  S(argo);                                                                     \
  S(argo##_ex);                                                                \
  S(argo) { argo##_ex(Args); }                                                 \
  S(argo##_ex)

#ifndef ChapterSize
#define ChapterSize 16
#endif

N(bo);
