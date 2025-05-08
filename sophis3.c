/*
{ loadinput(); } most_abstract_definition {  }

sentence_member
  {parse_name}.                        // write Tword
  terminal.                            // write terminal
  action.                              // write terminal

sentence_members
  sentence_member.
  sentence_members space sentence_member.

sentence
  sentence_members dot.

name_defining_paragraph
  sentence.
  name_defining_paragraph space sentence.

name_defining_paragraphs
  name_defining_paragraph new_line.
  name_defining_paragraphs name_defining_paragraph new_line.

name
  {}.

new_line
  '\n'.                                   // align

most_abstract_definition
  name new_line name_defining_paragraphs.

*/
#include "common.h"

N(bo);
N(book_of_print);
N(defoff_0);

void showit() {}
void op() {}
void parse_name() {}
void parse_new_line() {}
void parse_char() {}
void parse_b() {}
void parse_a() {}
void parse_dot() {}
void parse_space() {}

#pragma GCC diagnostic ignored "-Wint-conversion"
// clang-format off
long ram[0x12000];
int main() {
  long *o = ram + 0x5000, b = 0, a = 0, s = 0x2000, r[8] = {o[s++] = 0};

#define os o[s++] = 
#define next        o[s++] = 8, o[s++] = o[r[Blue]+1]
#define beginning   o[s + 0] = 1,           \
                    o[s + 1] = r[Blue   ],  \
                    o[s + 2] = r[Green  ],  \
                    o[s + 3] = r[Yellow ],  \
                    o[s + 4] = r[Red    ],  \
                    r[Blue ] = s, s += 5,
#define tword(name) o[s++] = 2, o[s++] = name,
#define nl          o[s++] = 3
#define dword(name) o[s++] = 4, o[s++] = name,
#define dot         o[s++] = 5,
#define cword(name) o[s++] = 6, o[s++] = name,
#define sp          o[s++] = 7,

  beginning tword("most_abstract_definition") nl;

  dword("most_abstract_definition") nl;
  tword("name") tword("new_line") tword("name_defining_paragraphs") dot nl;

  dword("name") nl;
  cword(parse_name) dot nl;

  dword("new_line") nl;
  cword(parse_new_line) dot nl;

  dword("name_defining_paragraphs") nl;
  tword("name_defining_paragraph") tword("new_line") dot nl;
  tword("name_defining_paragraphs") tword("name_defining_paragraph") tword("new_line") dot nl;

  dword("name_defining_paragraph") nl;
  tword("sentence") dot nl;
  tword("name_defining_paragraph") tword("space") tword("sentence") dot nl;

  dword("sentence") nl;
  tword("sentence_members") tword("dot") dot nl;

  dword("sentence_members") nl;
  tword("sentence_member") tword("new_line") dot nl;
  tword("sentence_members") tword("space") tword("sentence_member") dot nl;

  dword("dot")
  cword(parse_dot) dot nl;

  dword("space")
  cword(parse_space) dot nl;

  dword("sentence_member") nl;
  cword(parse_name) dot nl;
  cword(parse_char) dot nl;
  next;

  beginning tword("S") nl;
  dword("S") nl;
  cword(parse_b) dot nl;
  tword("S") cword(parse_a) dot nl;
  next;
  
  printf("\n");
  printf("\n");
  o[--b] = book_of_print;
  o[--b] = defoff_0;

  long t = r[Blue];
  bo(Args);
}
