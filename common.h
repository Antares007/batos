#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"

#define N(argo)                                                                \
  void argo(long *o, long b, long a, long t, long s, long *__restrict r)
typedef N((*n_t));
typedef enum { Maroon, Olive, Lime, Navy, Blue, Green, Yellow, Red } Colors;

#include <stdio.h>

#define P printf("%s\n", __func__)

#define S(argo) static N(argo)
