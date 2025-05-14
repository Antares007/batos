#include "common.h"

N(bo);
N(bp_0);
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
void the_end() { P; }
#pragma GCC diagnostic ignored "-Wint-conversion"
// clang-format off
long ram[0x10000];

void stop() { P; }
void sophis3() {
  long *o = ram + 0x5000, b = 0, a = 0, t = 0, s = 0, r[8] = {};

#define beginning   o[s++] = 1,
#define tword(name) o[s++] = 2, o[s++] = name,
#define nl          o[s++] = 3, s += 15 & -16
#define dword(name) o[s++] = 4, o[s++] = name,
#define dot         o[s++] = 5,
#define cword(name) o[s++] = 6, o[s++] = name,
#define end         o[s++] = 0

  printf("\n");
  printf("\n");
}
/*
{beginning} most_abstract_definition

most_abstract_definition
  {name} {new_line} name_defining_paragraphs.

name_defining_paragraphs
  name_defining_paragraph {new_line}.
  name_defining_paragraphs name_defining_paragraph {new_line}.

name_defining_paragraph
  sentence.
  name_defining_paragraph {space} sentence.

sentence
  sentence_members {dot}.

sentence_members
  sentence_member.
  sentence_members {space} sentence_member.

sentence_member
  {name}.             // write Tword
  terminal.           // write terminal
  action.             // write terminal

*/
long write_most_abstract_definition(long*o) {
  long s = 0;
  beginning cword(0) tword("most_abstract_definition") nl;

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
  end;
  return s;
}
