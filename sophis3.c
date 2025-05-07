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
N(Print_book);
N(Green_book);
N(defoff_book);

N(beginning) { P, ((n_t)o[b])(b, a, t, o, s); }
void showit() {}
void op() {}
void parse_name() {}
void parse_new_line() {}
void parse_char() {}
void parse_dot() {}
void parse_space() {}

#pragma GCC diagnostic ignored "-Wint-conversion"
// clang-format off
long ram[0x10000];
int main() {
  long b = Maroon, a = Red + 1, t = a, *o = ram + 0x5000, s = a;




#define os o[s++] = 
#define beginning   o[s++] = 1,
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
  os 0;

  o[Blue] = s,
  printf("%ld\n", o[Blue]);

  defoff_book(b, a, t, o, s);
  //Print_book(b, a, t, o, s);
  //Green_book(b, a, t, o, s);
}

