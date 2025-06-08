#pragma GCC diagnostic ignored "-Wint-conversion"
#ifndef Ext
#define Ext long d
#define E d
#endif
#ifndef W
#define W 2
#endif

#define Cont long b, long *o, long t, struct Ray *u, long s
#define Context Cont, Ext
#define N(argo) long argo(Context)
#define S(argo) static N(argo)
#define C b, o, t, u, s
#define CE C, E

typedef struct Ray {
  struct Ray *upper;
  long t;
  long partition;
} Ray;

typedef N((*n_t));

typedef enum { Blue, Green, Yellow, Red, Pink } Rays;

const char *ray_names[] = {"Blue", "Green", "Yellow", "Red"};

#ifdef TWORD_IMPLEMENTATION
S(reTurn) { return t; }

static N(book_of_text);
S(ntm) { return book_of_text(b, o, t + W, u, s, E); }

S(conTinue) { return ntm(b, o, u->t, u->upper, s, E); }
S(conTinue_Blue) { return conTinue(Blue, o, t, u, s, E); }
S(conTinue_Green) { return conTinue(Green, o, t, u, s, E); }

S(grow_Red);
S(conTinue_OrAnd_grow_Red) { return conTinue(CE), grow_Red(CE); }
S(conTinue_Green_OrAnd_grow_Red) { return conTinue_Green(CE), grow_Red(CE); }
S(conTinue_Blue_OrAnd_grow_Red) { return conTinue_Blue(CE), grow_Red(CE); }
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
  return nars[b * 5 + u->partition](CE);
}

static N(book_of_grow);
S(grow_Yellow) { return book_of_grow(Yellow, o, 0, u, s, E); }
N(branch_and_grow_Yellow) {
  return grow_Yellow(b, o, t, &(Ray){.upper = u, .t = t, .partition = b}, s, E);
}

S(grow_Red) { return book_of_grow(Red, o, 0, u, s, E); }
S(branch_and_grow_Red) {
  return grow_Red(b, o, t, &(Ray){.upper = u, .t = t, .partition = b}, s, E);
}
S(branch_and_grow_Yellow_uos) {
  return branch_and_grow_Yellow(b, o, t, o[s], s, E);
}
S(return_or_branch_and_grow_Yellow_uos) {
  return o[u->t + 1] == o[t + 1] ? 1 : branch_and_grow_Yellow_uos(CE);
}
static N(book_of_recursion);
S(book_of_recursion_for_upper) {
  return book_of_recursion(b, o, t, u->upper, s, E);
}
S(return_or_book_of_recursion_for_upper) {
  return o[u->t + 1] == o[t + 1] ? 1 : book_of_recursion_for_upper(CE);
}
S(ntm_Blue) { return ntm(Blue, o, t, u, s, E); }
S(ntm_Blue_uos) { return ntm_Blue(b, o, t, o[s], s, E); }
S(branch_and_grow_Red_uos) { return branch_and_grow_Red(b, o, t, o[s], s, E); }

S(ntm_Blue_uos_or_branch_and_grow_Red_uos) {
  return (o[u->t + 1] == o[t + 1] ? ntm_Blue_uos : branch_and_grow_Red_uos)(CE);
}
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
  return nars[b * 5 + u->partition](CE);
}
static N(book_of_grow);
S(skip_ntm) { return book_of_grow(b, o, t + W, u, s, E); }
S(if_def_ntm_OrAnd_find_next_def_else_find_next_def) {
  if (o[u->t + 1] == o[t + 1])
    return ntm(CE), skip_ntm(CE);
  else
    return skip_ntm(CE);
}
S(book_of_grow) {
  static n_t nars[4] = {
      reTurn,                                            // 0
      if_def_ntm_OrAnd_find_next_def_else_find_next_def, // D(1)efintion
      skip_ntm,                                          // B(2)eginning
      skip_ntm,                                          // T(3)oti
  };
  return nars[o[t]](CE);
}
S(ok) { return ((n_t)o[s])(CE); }
S(os_book_of_recursion) { return o[s] = u, book_of_recursion(CE); }
S(dispatch_ntm) { return o[s] = ntm, ((n_t)o[t + 1])(CE); }
S(ntm_Green) { return ntm(Green, o, t, u, s, E); }
S(dispatch_ntm_Green) { return o[s] = ntm_Green, ((n_t)o[t + 1])(CE); }
S(book_of_text) {
  static n_t nars[4 * 4] = {
      book_of_continuation, // Blue
      book_of_continuation, // Blue_1
      dispatch_ntm,         // Blue_2
      os_book_of_recursion, // Blue_3
                            //
      book_of_continuation, // Green
      book_of_continuation, // Green_1
      dispatch_ntm,         // Green_2
      os_book_of_recursion, // Green_3
                            //
      book_of_continuation, // Yellow
      book_of_continuation, // Yellow_1
      dispatch_ntm_Green,   // Yellow_2
      os_book_of_recursion, // Yellow_3
                            //
      reTurn,               // Red
      reTurn,               // Red_1
      reTurn,               // Red_2
      os_book_of_recursion, // Red_3
  };
  return nars[b * 4 + o[t]](CE);
}
#endif
