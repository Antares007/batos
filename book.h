#pragma once
#define _STR(s) #s
#define STR(s) _STR(s)

#define Chapter                                                                \
  __attribute__((section(".text." __FILE_NAME__ STR(__LINE__))))               \
  __attribute__((__noinline__)) __attribute__((used))
