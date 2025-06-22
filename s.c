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
S(ntm                           ) { t += TextMemberWidth,
                                    x++, 
                                    cells = (long[]){x, y, t, b, cells},
                                    o[s] = book_of_text,                debug_draw(C); }
S(conTinue                      ) { y = u->y, t = u->t,  u = u->upper,  ntm(C); }
S(conTinue_Blue                 ) { b = Blue,                           conTinue(C); }
S(conTinue_Green                ) { b = Green,                          conTinue(C); }
S(grow_Red);
S(conTinue_OrAnd_grow_Red       ) {                                     conTinue(C),
                                                                        grow_Red(C); }
S(conTinue_Green_OrAnd_grow_Red ) {                                     conTinue_Green(C),
                                                                        grow_Red(C); }
S(conTinue_Blue_OrAnd_grow_Red  ) {                                     conTinue_Blue(C),
                                                                        grow_Red(C); }
S(book_of_continuation) {
  static n_t nars[3 * 5] = {
      conTinue_OrAnd_grow_Red,       // Blue_Blue,
      conTinue_Green_OrAnd_grow_Red, // Blue_Green,
      conTinue_Green_OrAnd_grow_Red, // Blue_Yellow,
      conTinue,                      // Blue_Red,
      grow_Red,                      // Blue_Pink,
                                     //
      conTinue_Blue_OrAnd_grow_Red,  // Green_Blue,
      conTinue_OrAnd_grow_Red,       // Green_Green,
      conTinue_OrAnd_grow_Red,       // Green_Yellow,
      0,                             // Green_Red,
      grow_Red,                      // Green_Pink
                                     //
      conTinue_Blue,                 // Yellow_Blue
      conTinue_Green,                // Yellow_Green
      conTinue,                      // Yellow_Yellow
      0,                             // Yellow_Red
      reTurn,                        // Yellow_Pink
  };
  nars[b * 5 + u->partition](C);
}

static N(book_of_grow);
S(grow_Yellow                             ) { b = Yellow, t = 0,          book_of_grow(C); }
S(grow_Red                                ) { b = Red,    t = 0,          book_of_grow(C); }
S(branch_and_grow_Yellow                  ) { u = &(Cursor){u, t, b, y++},grow_Yellow(C); }
S(branch_and_grow_Red                     ) { u = &(Cursor){u, t, b, y++},grow_Red(C); }
S(branch_and_grow_Yellow_uos              ) { u = o[s],                   branch_and_grow_Yellow(C); }
S(return_or_branch_and_grow_Yellow_uos    ) { if(o[u->t + 1] != o[t + 1]) branch_and_grow_Yellow_uos(C); }
static N(book_of_recursion);
S(book_of_recursion_for_upper             ) { u = u->upper,               book_of_recursion(C); }
S(return_or_book_of_recursion_for_upper   ) { if(o[u->t + 1] != o[t + 1]) book_of_recursion_for_upper(C); }
S(ntm_Blue                                ) { b = Blue,                   ntm(C); }
S(ntm_Blue_uos                            ) { u = o[s],                   ntm_Blue(C); }
S(branch_and_grow_Red_uos                 ) { u = o[s],                   branch_and_grow_Red(C); }
S(ntm_Blue_uos_or_branch_and_grow_Red_uos ) { (o[u->t + 1] == o[t + 1] ?  ntm_Blue_uos
                                                                       :  branch_and_grow_Red_uos)(C); }
S(book_of_recursion) {
  static n_t nars[4 * 5] = {
      branch_and_grow_Yellow,                  // Blue_Blue,
      branch_and_grow_Yellow,                  // Blue_Green,
      branch_and_grow_Yellow,                  // Blue_Yellow,
      branch_and_grow_Yellow,                  // Blue_Red,
      branch_and_grow_Yellow,                  // Blue_Pink,
                                               //
      branch_and_grow_Yellow,                  // Green_Blue,
      branch_and_grow_Yellow,                  // Green_Green,
      branch_and_grow_Yellow,                  // Green_Yellow,
      0,                                       // Green_Red,
      branch_and_grow_Yellow,                  // Green_Pink,
                                               //
      return_or_branch_and_grow_Yellow_uos,    // Yellow_Blue
      return_or_branch_and_grow_Yellow_uos,    // Yellow_Green
      return_or_book_of_recursion_for_upper,   // Yellow_Yellow
      0,                                       // Yellow_Red
      return_or_branch_and_grow_Yellow_uos,    // Yellow_Pink
                                               //
      ntm_Blue_uos_or_branch_and_grow_Red_uos, // Red_Blue
      ntm_Blue_uos_or_branch_and_grow_Red_uos, // Red_Green
      ntm_Blue_uos_or_branch_and_grow_Red_uos, // Red_Yellow
      return_or_book_of_recursion_for_upper,   // Red_Red
      ntm_Blue_uos_or_branch_and_grow_Red_uos, // Red_Pink
  };
  nars[b * 5 + u->partition](C);
}
static N(book_of_grow);
S(skip_ntm) { t += TextMemberWidth, book_of_grow(C); }
S(if_def_ntm_OrAnd_find_next_def_else_find_next_def) {
  if (o[u->t + 1] == o[t + 1])
    ntm(C), skip_ntm(C);
  else
    skip_ntm(C);
}
S(book_of_grow) {
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
      book_of_continuation, // Blue
      book_of_continuation, // Blue_1
      ntm,                  // Blue_2
      os_book_of_recursion, // Blue_3
                            //
      book_of_continuation, // Green
      book_of_continuation, // Green_1
      ntm,                  // Green_2
      os_book_of_recursion, // Green_3
                            //
      book_of_continuation, // Yellow
      book_of_continuation, // Yellow_1
      ntm_Green,            // Yellow_2
      os_book_of_recursion, // Yellow_3
                            //
      reTurn,               // Red
      reTurn,               // Red_1
      reTurn,               // Red_2
      os_book_of_recursion, // Red_3
  };
  nars[b * 4 + o[t]](C);
}

void debug_close(void);
void debug_init(void);
int main() {
  long o[2048];
  long s = 0;

#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = b
#define T(S) o[s++] = 3, o[s++] = S

  // D('3'), T('T'), T('T'), T('T');
  // D('T'), B('t');
  // D('T'), B('a');
  // D('T'), B('b');
  
  // D('A'), B('a');
  // D('A'), T('B'), B('o');
  // D('B'), B('b');
  // D('B'), T('C'), B('d');
  // D('C'), B('c');
  // D('C'), T('A'), B('t');

  // D('S'), B('b');
  // D('S'), T('S'), B('a');
  // D('S'), T('S'), B('t'), T('O');
  // D('O');
  // D('O'), B('o');


  //D('N'), T('1'), T('2'), T('3');
  //D('1'), B('o'), B('n'), B('e');
  //D('1'), B('1');
  //D('2'), B('t'), B('w'), B('o');
  //D('2'), B('2');
  //D('3'), B('t'), B('h'), B('r'), B('e'), B('e');
  //D('3'), B('3');

  // D('R');
  // D('R'), B('b'), T('R'), T('R');

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
  branch_and_grow_Yellow(Pink, o, 0, 0, s, 0, 0, (long[]){0, 0, 0, Pink, 0});
  debug_close();
}
