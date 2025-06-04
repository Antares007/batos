#pragma GCC diagnostic ignored "-Wint-conversion"

#ifndef Ext
#define Ext long d
#define E d
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
S(next_text_member) { return book_of_text(b, o, t + 2, u, s, E); }

S(continue_toti) { return next_text_member(b, o, u->t, u->upper, s, E); }
S(continue_toti_as_Blue) { return continue_toti(Blue, o, t, u, s, E); }
S(continue_toti_as_Green) { return continue_toti(Green, o, t, u, s, E); }

S(branch_with_Red_pith);
S(continue_toti_orand_branch_with_Red_pith) {
  return continue_toti(CE), branch_with_Red_pith(CE);
}
S(continue_toti_as_Green_orand_branch_with_Red_pith) {
  return continue_toti_as_Green(CE), branch_with_Red_pith(CE);
}
S(continue_toti_as_Blue_orand_branch_with_Red_pith) {
  return continue_toti_as_Blue(CE), branch_with_Red_pith(CE);
}
S(book_of_continuation) {
  static n_t nars[3 * 5] = {
      continue_toti_orand_branch_with_Red_pith,          // Blue_Blue,
      continue_toti_as_Green_orand_branch_with_Red_pith, // Blue_Green,
      continue_toti_as_Green_orand_branch_with_Red_pith, // Blue_Yellow,
      continue_toti,                                     // Blue_Red,
      branch_with_Red_pith,                              // Blue_Pink,
                                                         //
      continue_toti_as_Blue_orand_branch_with_Red_pith,  // Green_Blue,
      continue_toti_orand_branch_with_Red_pith,          // Green_Green,
      continue_toti_orand_branch_with_Red_pith,          // Green_Yellow,
      0,                                                 // Green_Red,
      branch_with_Red_pith,                              // Green_Pink
                                                         //
      continue_toti_as_Blue,                             // Yellow_Blue
      continue_toti_as_Green,                            // Yellow_Green
      continue_toti,                                     // Yellow_Yellow
      0,                                                 // Yellow_Red
      reTurn,                                            // Yellow_Pink
  };
  return nars[b * 5 + u->partition](CE);
}

static N(book_of_branching);
N(grow_toti_with_Yellow_pith) {
  return book_of_branching(Yellow, o, 0,
                           &(Ray){.upper = u, .t = t, .partition = b}, s, E);
}

S(branch_with_Red_pith) { return book_of_branching(Red, o, 0, u, s, E); }
S(grow_toti_with_Red_pith) {
  return branch_with_Red_pith(b, o, t,
                              &(Ray){.upper = u, .t = t, .partition = b}, s, E);
}
S(return_or_grow_toti_with_Yellow_pith) {
  return o[u->t + 1] == o[t + 1]
             ? 1
             : grow_toti_with_Yellow_pith(b, o, t, o[s], s, E);
}
static N(book_of_recursion);
S(book_of_recursion_for_upper) {
  return book_of_recursion(b, o, t, u->upper, s, E);
}
S(return_or_book_of_recursion_for_upper) {
  return o[u->t + 1] == o[t + 1] ? 1 : book_of_recursion_for_upper(CE);
}
S(next_text_member_as_Blue) { return next_text_member(Blue, o, t, u, s, E); }
S(next_text_member_as_Blue_or_grow_toti_with_Red_pith) {
  return (o[u->t + 1] == o[t + 1]
              ? next_text_member_as_Blue
              : grow_toti_with_Red_pith)(b, o, t, o[s], s, E);
}
S(book_of_recursion) {
  static n_t nars[4 * 5] = {
      grow_toti_with_Yellow_pith,                          // Blue_Blue,
      grow_toti_with_Yellow_pith,                          // Blue_Green,
      grow_toti_with_Yellow_pith,                          // Blue_Yellow,
      grow_toti_with_Yellow_pith,                          // Blue_Red,
      grow_toti_with_Yellow_pith,                          // Blue_Pink,
                                                           //
      grow_toti_with_Yellow_pith,                          // Green_Blue,
      grow_toti_with_Yellow_pith,                          // Green_Green,
      grow_toti_with_Yellow_pith,                          // Green_Yellow,
      0,                                                   // Green_Red,
      grow_toti_with_Yellow_pith,                          // Green_Pink,
                                                           //
      return_or_grow_toti_with_Yellow_pith,                // Yellow_Blue
      return_or_grow_toti_with_Yellow_pith,                // Yellow_Green
      return_or_book_of_recursion_for_upper,               // Yellow_Yellow
      0,                                                   // Yellow_Red
      return_or_grow_toti_with_Yellow_pith,                // Yellow_Pink
                                                           //
      next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Blue
      next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Green
      next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Yellow
      return_or_book_of_recursion_for_upper,               // Red_Red
      next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Pink
  };
  return nars[b * 5 + u->partition](CE);
}
static N(book_of_branching);
S(skip_next_text_member) { return book_of_branching(b, o, t + 2, u, s, E); }
S(if_def_next_text_member_orand_find_next_def) {
  if (o[u->t + 1] == o[t + 1])
    next_text_member(CE);
  return skip_next_text_member(CE);
}
S(book_of_branching) {
  static n_t nars[4] = {
      reTurn,                                      // 0
      if_def_next_text_member_orand_find_next_def, // D(1)efintion
      skip_next_text_member,                       // B(2)eginning
      skip_next_text_member,                       // T(3)oti
  };
  return nars[o[t]](CE);
}
S(ok) { return ((n_t)o[s])(CE); }
S(os_book_of_recursion) { return o[s] = u, book_of_recursion(CE); }
S(dispatch_next_text_member) {
  return o[s] = next_text_member, ((n_t)o[t + 1])(CE);
}
S(next_text_member_as_Green) { return next_text_member(Green, o, t, u, s, E); }
S(dispatch_next_text_member_as_Green) {
  return o[s] = next_text_member_as_Green, ((n_t)o[t + 1])(CE);
}
S(book_of_text) {
  static n_t nars[4 * 4] = {
      book_of_continuation,               // Blue
      book_of_continuation,               // Blue_1
      dispatch_next_text_member,          // Blue_2
      os_book_of_recursion,               // Blue_3
                                          //
      book_of_continuation,               // Green
      book_of_continuation,               // Green_1
      dispatch_next_text_member,          // Green_2
      os_book_of_recursion,               // Green_3
                                          //
      book_of_continuation,               // Yellow
      book_of_continuation,               // Yellow_1
      dispatch_next_text_member_as_Green, // Yellow_2
      os_book_of_recursion,               // Yellow_3
                                          //
      reTurn,                             // Red
      reTurn,                             // Red_1
      reTurn,                             // Red_2
      os_book_of_recursion,               // Red_3
  };
  return nars[b * 4 + o[t]](CE);
}
#endif
