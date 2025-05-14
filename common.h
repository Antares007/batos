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

#define _STR(s) #s
#define STR(s) _STR(s)

#define Chapter                                                                \
  __attribute__((section("." __FILE_NAME__ STR(__LINE__))))                    \
  __attribute__((noinline))

#ifndef ChapterSize
#define ChapterSize 16
#endif
#ifndef NMAP
#define NMAP "this is set by Makefile"
#endif

N(bo);
