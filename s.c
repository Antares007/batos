#pragma GCC diagnostic ignored "-Wint-conversion"

#define Context long b, long *o, long t, struct Ray *u, long s, long d
#define N(argo) long argo(Context)
#define C b, o, t, u, s

typedef struct Ray {
  struct Ray *upper;
  long t;
  long partition;
} Ray;

typedef N((*n_t));
typedef enum { Blue, Green, Yellow, Red, Pink } Rays;
static const char *ray_names[] = {"Blue", "Green", "Yellow", "Red"};

#define S(argo) static N(argo)

S(reTurn) { return t; }

static N(book_of_text);
S(next_text_member) { return book_of_text(b, o, t + 2, u, s, d); }

S(continue_toti) { return next_text_member(b, o, u->t, u->upper, s, d); }
S(continue_toti_as_Blue) { return continue_toti(Blue, o, t, u, s, d); }
S(continue_toti_as_Green) { return continue_toti(Green, o, t, u, s, d); }

S(branch_with_Red_pith);
S(continue_toti_orand_branch_with_Red_pith) {
  return continue_toti(C, d), branch_with_Red_pith(C, d);
}
S(continue_toti_as_Green_orand_branch_with_Red_pith) {
  return continue_toti_as_Green(C, d), branch_with_Red_pith(C, d);
}
S(continue_toti_as_Blue_orand_branch_with_Red_pith) {
  return continue_toti_as_Blue(C, d), branch_with_Red_pith(C, d);
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
  return nars[b * 5 + u->partition](C, d);
}

static N(book_of_branching);
N(grow_toti_with_Yellow_pith) {
  return book_of_branching(Yellow, o, 0,
                           &(Ray){.upper = u, .t = t, .partition = b}, s, d);
}

S(branch_with_Red_pith) { return book_of_branching(Red, o, 0, u, s, d); }
S(grow_toti_with_Red_pith) {
  return branch_with_Red_pith(b, o, t,
                              &(Ray){.upper = u, .t = t, .partition = b}, s, d);
}
S(return_or_grow_toti_with_Yellow_pith) {
  return o[u->t + 1] == o[t + 1]
             ? 1
             : grow_toti_with_Yellow_pith(b, o, t, o[s], s, d);
}
static N(book_of_recursion);
S(book_of_recursion_for_upper) {
  return book_of_recursion(b, o, t, u->upper, s, d);
}
S(return_or_book_of_recursion_for_upper) {
  return o[u->t + 1] == o[t + 1] ? 1 : book_of_recursion_for_upper(C, d);
}
S(next_text_member_as_Blue) { return next_text_member(Blue, o, t, u, s, d); }
S(next_text_member_as_Blue_or_grow_toti_with_Red_pith) {
  return (o[u->t + 1] == o[t + 1]
              ? next_text_member_as_Blue
              : grow_toti_with_Red_pith)(b, o, t, o[s], s, d);
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
  return nars[b * 5 + u->partition](C, d);
}
static N(book_of_branching);
S(skip_next_text_member) { return book_of_branching(b, o, t + 2, u, s, d); }
S(if_def_next_text_member_orand_find_next_def) {
  if (o[u->t + 1] == o[t + 1])
    next_text_member(C, d);
  return skip_next_text_member(C, d);
}
S(book_of_branching) {
  static n_t nars[4] = {
      reTurn,                                      // 0
      if_def_next_text_member_orand_find_next_def, // D(1)efintion
      skip_next_text_member,                       // B(2)eginning
      skip_next_text_member,                       // T(3)oti
  };
  return nars[o[t]](C, d);
}
S(ok) { return ((n_t)o[s])(C, d); }
S(os_book_of_recursion) { return o[s] = u, book_of_recursion(C, d); }
S(dispatch_next_text_member) {
  return o[s] = next_text_member, ((n_t)o[t + 1])(C, d);
}
S(next_text_member_as_Green) { return next_text_member(Green, o, t, u, s, d); }
S(dispatch_next_text_member_as_Green) {
  return o[s] = next_text_member_as_Green, ((n_t)o[t + 1])(C, d);
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
  return nars[b * 4 + o[t]](C, d);
}
static char str[1024];
extern int printf(const char *restrict __format, ...);
#define Length 4
// clang-foramt off
S(term_t) { return (Length == d ? 0 : (str[d] = 't', ok(C, d + 1))); }
S(term_a) { return (Length == d ? 0 : (str[d] = 'a', ok(C, d + 1))); }
S(term_b) { return (Length == d ? 0 : (str[d] = 'b', ok(C, d + 1))); }
S(term_o) { return (Length == d ? 0 : (str[d] = 'o', ok(C, d + 1))); }
S(term_s) { return (Length == d ? 0 : (str[d] = 's', ok(C, d + 1))); }
S(term_1) { return (Length == d ? 0 : (str[d] = '1', ok(C, d + 1))); }
S(term_2) { return (Length == d ? 0 : (str[d] = '2', ok(C, d + 1))); }
S(term_3) { return (Length == d ? 0 : (str[d] = '3', ok(C, d + 1))); }
// clang-foramt on

S(term_nl) {
  str[d] = '\0';
  printf("%s\n", str);
  return ok(C, d);
}

// book oriented programming
// book operator?
int main() {
  long o[2048];
  long s = 0;
#define D(S) o[s++] = 1, o[s++] = S
#define B(b) o[s++] = 2, o[s++] = term_##b
#define T(S) o[s++] = 3, o[s++] = S

  D('_'), T('3'), B(nl);
  D('_'), T('S'), B(nl);
  D('_'), T('A'), B(nl);
  D('T'), B(t);
  D('N'), B(1);
  D('T'), B(a);
  D('3'), T('T'), T('T'), T('T');
  D('N'), B(2);
  D('N'), B(3);
  D('T'), B(b);

  D('S'), B(b);
  D('S'), T('S'), B(a);
  D('S'), T('S'), B(t), T('O');
  D('O');
  D('O'), B(o);

  D('A'), B(b);
  D('A'), T('B'), B(a);
  D('B'), B(t);
  D('B'), T('A'), B(s);

  o[s++] = 0;
  o[s++] = 0;

  grow_toti_with_Yellow_pith(Pink, o, 0, 0, s, 0);
  return 0;
}
/*

primary_expression:
  constant
  (expression)

unary-expression:
  primary-expression
  unary_operator unary_expression
unary_operator: one of
  & * + - ~ !


multiplicative_expression:
  unary_expression
  multiplicative_expression * unary_expression
  multiplicative_expression / unary_expression
  multiplicative_expression % unary_expression

additive_expression:
  multiplicative_expression
  additive_expression + multiplicative_expression
  additive_expression - multiplicative_expression

expression:
  additive_expression
            */
