#include <linux/limits.h>
#pragma GCC diagnostic ignored "-Wint-conversion"
#define NDEBUG
#define TextMemberWidth 2
#define Context                                                                \
  long b, long *o, long t, struct Cursor *u, long s, long x, long y, long *cells
#define C b, o, t, u, s, x, y, cells
#define N(argo) void argo(Context)
#define S(argo) static N(argo)

typedef struct Cursor {
  struct Cursor *upper;
  long t;
  long partition;
  long y;
} Cursor;

typedef N((*n_t));
typedef enum { Blue, Green, Yellow, Red, Pink } Rays;

// clang-format off
S(reTurn                        ) { }

N(debug_draw);
static N(book_of_text);

/// ntm - next text member
S(ntm                             ) { t += TextMemberWidth,
                                      x++, 
                                      cells = (long[]){x, y, t, b, cells},
                                      o[s] = book_of_text,                debug_draw(C);  }
S(conTinue                        ) { y = u->y, t = u->t,  u = u->upper,  ntm(C);         }
S(conTinue_Blue                   ) { b = Blue,                           conTinue(C);    }
S(conTinue_Green                  ) { b = Green,                          conTinue(C);    }
S(Red_choice);
S(conTinue_OrAnd_Red_choice       ) {                                     conTinue(C),      Red_choice(C);  }
S(conTinue_Green_OrAnd_Red_choice ) {                                     conTinue_Green(C),Red_choice(C);  }
S(conTinue_Blue_OrAnd_Red_choice  ) {                                     conTinue_Blue(C), Red_choice(C);  }
S(book_of_continuation) {
  static n_t nars[3 * 5] = {
      conTinue_OrAnd_Red_choice,        // Blue_Blue,
      conTinue_Green_OrAnd_Red_choice,  // Blue_Green,
      conTinue_Green_OrAnd_Red_choice,  // Blue_Yellow,
      conTinue,                         // Blue_Red,
      Red_choice,                       // Blue_Pink,
                                        //
      conTinue_Blue_OrAnd_Red_choice,   // Green_Blue,
      conTinue_OrAnd_Red_choice,        // Green_Green,
      conTinue_OrAnd_Red_choice,        // Green_Yellow,
      0,                                // Green_Red,
      Red_choice,                       // Green_Pink
                                        //
      conTinue_Blue,                    // Yellow_Blue
      conTinue_Green,                   // Yellow_Green
      conTinue,                         // Yellow_Yellow
      0,                                // Yellow_Red
      reTurn,                           // Yellow_Pink
  };
  nars[b * 5 + u->partition](C);
}

static N(book_of_choice);
S(Yellow_choice                             ) { b = Yellow, t = 0,          book_of_choice(C); }
S(Red_choice                                ) { b = Red,    t = 0,          book_of_choice(C); }
S(branch_and_Yellow_choice                  ) { u = &(Cursor){u, t, b, y++},Yellow_choice(C); }
S(branch_and_Red_choice                     ) { u = &(Cursor){u, t, b, y++},Red_choice(C); }
S(branch_and_Yellow_choice_uos              ) { u = o[s],                   branch_and_Yellow_choice(C); }
S(return_or_branch_and_Yellow_choice_uos    ) { if(o[u->t + 1] != o[t + 1]) branch_and_Yellow_choice_uos(C); }
static N(book_of_recursion);
S(book_of_recursion_for_upper               ) { u = u->upper,               book_of_recursion(C); }
S(return_or_book_of_recursion_for_upper     ) { if(o[u->t + 1] != o[t + 1]) book_of_recursion_for_upper(C); }
S(ntm_Blue                                  ) { b = Blue,                   ntm(C); }
S(ntm_Blue_uos                              ) { u = o[s],                   ntm_Blue(C); }
S(branch_and_Red_choice_uos                 ) { u = o[s],                   branch_and_Red_choice(C); }
S(ntm_Blue_uos_or_branch_and_Red_choice_uos ) { (o[u->t + 1] == o[t + 1] ?  ntm_Blue_uos
                                                                         :  branch_and_Red_choice_uos)(C); }
S(book_of_recursion) {
  static n_t nars[4 * 5] = {
      branch_and_Yellow_choice,                   // Blue_Blue,
      branch_and_Yellow_choice,                   // Blue_Green,
      branch_and_Yellow_choice,                   // Blue_Yellow,
      branch_and_Yellow_choice,                   // Blue_Red,
      branch_and_Yellow_choice,                   // Blue_Pink,
                                                  //
      branch_and_Yellow_choice,                   // Green_Blue,
      branch_and_Yellow_choice,                   // Green_Green,
      branch_and_Yellow_choice,                   // Green_Yellow,
      0,                                          // Green_Red,
      branch_and_Yellow_choice,                   // Green_Pink,
                                                  //
      return_or_branch_and_Yellow_choice_uos,     // Yellow_Blue
      return_or_branch_and_Yellow_choice_uos,     // Yellow_Green
      return_or_book_of_recursion_for_upper,      // Yellow_Yellow
      0,                                          // Yellow_Red
      return_or_branch_and_Yellow_choice_uos,     // Yellow_Pink
                                                  //
      ntm_Blue_uos_or_branch_and_Red_choice_uos,  // Red_Blue
      ntm_Blue_uos_or_branch_and_Red_choice_uos,  // Red_Green
      ntm_Blue_uos_or_branch_and_Red_choice_uos,  // Red_Yellow
      return_or_book_of_recursion_for_upper,      // Red_Red
      ntm_Blue_uos_or_branch_and_Red_choice_uos,  // Red_Pink
  };
  nars[b * 5 + u->partition](C);
}
static N(book_of_choice);
S(skip_ntm) { t += TextMemberWidth, book_of_choice(C); }
S(if_def_ntm_OrAnd_find_next_def_else_find_next_def) {
  if (o[u->t + 1] == o[t + 1]) ntm(C);
  skip_ntm(C);
}
S(book_of_choice) {
  static n_t nars[4] = {
      reTurn,                                            // 0
      if_def_ntm_OrAnd_find_next_def_else_find_next_def, // D(1)efintion
      skip_ntm,                                          // B(2)eginning
      skip_ntm,                                          // T(3)oti
  };
  nars[o[t]](C);
}
S(os_book_of_recursion) { o[s] = u, book_of_recursion(C); }
S(ntm_Green) { b = Green, ntm(C); }
S(book_of_text) {
  static n_t nars[4 * 4] = {
      book_of_continuation, // Blue_0
      book_of_continuation, // Blue_D
      ntm,                  // Blue_B
      os_book_of_recursion, // Blue_T
                            //
      book_of_continuation, // Green_0
      book_of_continuation, // Green_D
      ntm,                  // Green_B
      os_book_of_recursion, // Green_T
                            //
      book_of_continuation, // Yellow_0
      book_of_continuation, // Yellow_D
      ntm_Green,            // Yellow_B
      os_book_of_recursion, // Yellow_T
                            //
      reTurn,               // Red_0
      reTurn,               // Red_D
      reTurn,               // Red_B
      os_book_of_recursion, // Red_T
  };
  nars[b * 4 + o[t]](C);
}
#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S

void debug_close(void);
void debug_init(void);
int main() {
  long o[2048];
  long s = 0;

  //D('1'), T('2'), B('a');
  //D('2'), T('3'), B('b');
  //D('3'), T('T'), T('T'), T('T');

  //D('S'), B('b');
  //D('S'), T('S'), B('a');
  //D('S'), B('t');
  //D('S'), T('S'), B('o');

  //D('S'), T('S'), B('t');
  //D('T'), B('t');
  //D('T'), B('a');
  //D('T'), B('b');
  
  //D('A'), B('a');
  //D('A'), T('B'), B('1');
  //D('B'), B('b');
  //D('B'), T('C'), B('2');
  //D('B'), T('A'), B('3');
  //D('C'), B('c');
  //D('C'), T('A'), B('4');
  //D('C'), T('A'), B('5');

  //D('0'), T('1'), B('1');
  //D('1'), T('S'), B('c');


  //D('N'), T('1'), T('2'), T('3');
  //D('1'), B('o'), B('n'), B('e');
  //D('1'), B('1');
  //D('2'), B('t'), B('w'), B('o');
  //D('2'), B('2');
  //D('3'), B('t'), B('h'), B('r'), B('e'), B('e');
  //D('3'), B('3');

  //D('-'), T('R'), B('c');
  //D('R'), B('b');
  //D('R'), T('R');

  //D('R');
  //D('R'), B('b'), T('R'), T('R');
  D('E'), T('A');
  D('A'), T('M');
  D('A'), T('A'), B('+'), T('M');
  D('A'), T('A'), B('-'), T('M');
  D('M'), T('U');
  D('M'), T('M'), B('*'), T('U');
  D('M'), T('M'), B('/'), T('U');
  D('U'), T('P');
  D('U'), B('-'), T('U');
  D('U'), B('!'), T('U');
  D('P'), T('C');
  D('P'), B('('), T('E'), B(')');
  D('C'), B('1');
  D('C'), B('2');
  D('C'), B('3');

  o[s++] = 0;
  o[s++] = '0';

  debug_init();
  branch_and_Yellow_choice(Pink, o, 0, 0, s, 0, 0, (long[]){0, 0, 0, Pink, 0});
  debug_close();
}
