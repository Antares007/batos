#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"

#define N(argo) void argo(long b, long a, long t, long *o, long s)
typedef N((*n_t));
typedef enum { Maroon, Olive, Lime, Navy, Blue, Green, Yellow, Red } Colors;

#include <stdio.h>
#define P printf("%s\n", __func__)
#define S(argo) static N(argo)
