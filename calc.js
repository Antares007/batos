const ray_names = [ "Blue", "Green", "Yellow", "Red" ];

class Ray {
  constructor() {
    this.upper = null;
    this.t = 0;
    this.partition = 0;
  }
}

const Rays = {
  Blue : 0,
  Green : 1,
  Yellow : 2,
  Red : 3,
  Pink : 4
};

function reTurn(b, o, t, u, s, d, sum) { return t; }

function next_text_member(b, o, t, u, s, d, sum) {
  return book_of_text(b, o, t + 2, u, s, d, sum);
}

function continue_toti(b, o, t, u, s, d, sum) {
  return next_text_member(b, o, u.t, u.upper, s, d, sum);
}

function continue_toti_as_Blue(b, o, t, u, s, d, sum) {
  return continue_toti(Rays.Blue, o, t, u, s, d, sum);
}

function continue_toti_as_Green(b, o, t, u, s, d, sum) {
  return continue_toti(Rays.Green, o, t, u, s, d, sum);
}

function branch_with_Red_pith(b, o, t, u, s, d, sum) {
  return book_of_branching(Rays.Red, o, 0, u, s, d, sum);
}

function continue_toti_orand_branch_with_Red_pith(b, o, t, u, s, d, sum) {
  return continue_toti(b, o, t, u, s, d, sum),
         branch_with_Red_pith(b, o, t, u, s, d, sum);
}

function continue_toti_as_Green_orand_branch_with_Red_pith(b, o, t, u, s, d,
                                                           sum) {
  return continue_toti_as_Green(b, o, t, u, s, d, sum),
         branch_with_Red_pith(b, o, t, u, s, d, sum);
}

function continue_toti_as_Blue_orand_branch_with_Red_pith(b, o, t, u, s, d,
                                                          sum) {
  return continue_toti_as_Blue(b, o, t, u, s, d, sum),
         branch_with_Red_pith(b, o, t, u, s, d, sum);
}

function book_of_continuation(b, o, t, u, s, d, sum) {
  const nars = [
    continue_toti_orand_branch_with_Red_pith,          // Blue_Blue,
    continue_toti_as_Green_orand_branch_with_Red_pith, // Blue_Green,
    continue_toti_as_Green_orand_branch_with_Red_pith, // Blue_Yellow,
    continue_toti,                                     // Blue_Red,
    branch_with_Red_pith,                              // Blue_Pink,
    //
    continue_toti_as_Blue_orand_branch_with_Red_pith, // Green_Blue,
    continue_toti_orand_branch_with_Red_pith,         // Green_Green,
    continue_toti_orand_branch_with_Red_pith,         // Green_Yellow,
    null,                                             // Green_Red,
    branch_with_Red_pith,                             // Green_Pink
    //
    continue_toti_as_Blue,  // Yellow_Blue
    continue_toti_as_Green, // Yellow_Green
    continue_toti,          // Yellow_Yellow
    null,                   // Yellow_Red
    reTurn,                 // Yellow_Pink
  ];
  return nars[b * 5 + u.partition](b, o, t, u, s, d, sum);
}

function grow_toti_with_Yellow_pith(b, o, t, u, s, d, sum) {
  const newRay = new Ray();
  newRay.upper = u;
  newRay.t = t;
  newRay.partition = b;
  return book_of_branching(Rays.Yellow, o, 0, newRay, s, d, sum);
}

function branch_with_Red_pith(b, o, t, u, s, d, sum) {
  return book_of_branching(Rays.Red, o, 0, u, s, d, sum);
}

function grow_toti_with_Red_pith(b, o, t, u, s, d, sum) {
  const newRay = new Ray();
  newRay.upper = u;
  newRay.t = t;
  newRay.partition = b;
  return branch_with_Red_pith(b, o, t, newRay, s, d, sum);
}

function return_or_grow_toti_with_Yellow_pith(b, o, t, u, s, d, sum) {
  return o[u.t + 1] == o[t + 1]
             ? 1
             : grow_toti_with_Yellow_pith(b, o, t, o[s], s, d, sum);
}

function book_of_recursion_for_upper(b, o, t, u, s, d, sum) {
  return book_of_recursion(b, o, t, u.upper, s, d, sum);
}

function return_or_book_of_recursion_for_upper(b, o, t, u, s, d, sum) {
  return o[u.t + 1] == o[t + 1]
             ? 1
             : book_of_recursion_for_upper(b, o, t, u, s, d, sum);
}

function next_text_member_as_Blue(b, o, t, u, s, d, sum) {
  return next_text_member(Rays.Blue, o, t, u, s, d, sum);
}

function next_text_member_as_Blue_or_grow_toti_with_Red_pith(b, o, t, u, s, d,
                                                             sum) {
  return (o[u.t + 1] == o[t + 1]
              ? next_text_member_as_Blue
              : grow_toti_with_Red_pith)(b, o, t, o[s], s, d, sum);
}

function book_of_recursion(b, o, t, u, s, d, sum) {
  const nars = [
    grow_toti_with_Yellow_pith, // Blue_Blue,
    grow_toti_with_Yellow_pith, // Blue_Green,
    grow_toti_with_Yellow_pith, // Blue_Yellow,
    grow_toti_with_Yellow_pith, // Blue_Red,
    grow_toti_with_Yellow_pith, // Blue_Pink,
    //
    grow_toti_with_Yellow_pith, // Green_Blue,
    grow_toti_with_Yellow_pith, // Green_Green,
    grow_toti_with_Yellow_pith, // Green_Yellow,
    null,                       // Green_Red,
    grow_toti_with_Yellow_pith, // Green_Pink,
    //
    return_or_grow_toti_with_Yellow_pith,  // Yellow_Blue
    return_or_grow_toti_with_Yellow_pith,  // Yellow_Green
    return_or_book_of_recursion_for_upper, // Yellow_Yellow
    null,                                  // Yellow_Red
    return_or_grow_toti_with_Yellow_pith,  // Yellow_Pink
    //
    next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Blue
    next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Green
    next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Yellow
    return_or_book_of_recursion_for_upper,               // Red_Red
    next_text_member_as_Blue_or_grow_toti_with_Red_pith, // Red_Pink
  ];
  return nars[b * 5 + u.partition](b, o, t, u, s, d, sum);
}

function skip_next_text_member(b, o, t, u, s, d, sum) {
  return book_of_branching(b, o, t + 2, u, s, d, sum);
}

function if_def_next_text_member_orand_find_next_def(b, o, t, u, s, d, sum) {
  if (o[u.t + 1] == o[t + 1]) {
    next_text_member(b, o, t, u, s, d, sum);
  }
  return skip_next_text_member(b, o, t, u, s, d, sum);
}

function book_of_branching(b, o, t, u, s, d, sum) {
  const nars = [
    reTurn,                                      // 0
    if_def_next_text_member_orand_find_next_def, // D(1)efintion
    skip_next_text_member,                       // B(2)eginning
    skip_next_text_member,                       // T(3)oti
  ];
  return nars[o[t]](b, o, t, u, s, d, sum);
}

function ok(b, o, t, u, s, d, sum) { return o[s](b, o, t, u, s, d, sum); }

function os_book_of_recursion(b, o, t, u, s, d, sum) {
  o[s] = u;
  return book_of_recursion(b, o, t, u, s, d, sum);
}

function dispatch_next_text_member(b, o, t, u, s, d, sum) {
  o[s] = next_text_member;
  return o[t + 1](b, o, t, u, s, d, sum);
}

function next_text_member_as_Green(b, o, t, u, s, d, sum) {
  return next_text_member(Rays.Green, o, t, u, s, d, sum);
}

function dispatch_next_text_member_as_Green(b, o, t, u, s, d, sum) {
  o[s] = next_text_member_as_Green;
  return o[t + 1](b, o, t, u, s, d, sum);
}

function book_of_text(b, o, t, u, s, d, sum) {
  const nars = [
    book_of_continuation,      // Blue
    book_of_continuation,      // Blue_1
    dispatch_next_text_member, // Blue_2
    os_book_of_recursion,      // Blue_3
    //
    book_of_continuation,      // Green
    book_of_continuation,      // Green_1
    dispatch_next_text_member, // Green_2
    os_book_of_recursion,      // Green_3
    //
    book_of_continuation,               // Yellow
    book_of_continuation,               // Yellow_1
    dispatch_next_text_member_as_Green, // Yellow_2
    os_book_of_recursion,               // Yellow_3
    //
    reTurn,               // Red
    reTurn,               // Red_1
    reTurn,               // Red_2
    os_book_of_recursion, // Red_3
  ];
  return nars[b * 4 + o[t]](b, o, t, u, s, d, sum);
}

const Length = 10;
let str = Buffer.alloc(1024);
let sum = 0;

// Term functions
function term_1(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '1'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, [ 1, sum ]);
}

function term_2(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '2'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, [ 2, sum ]);
}

function term_3(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '3'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, [ 3, sum ]);
}

function term_open_paren(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '('.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_close_paren(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = ')'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_minus(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '-'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_plus(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '+'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_mul(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '*'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_div(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '/'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}

function term_bang(b, o, t, u, s, d, sum) {
  if (Length === d)
    return 0;
  str[d] = '!'.charCodeAt(0);
  return ok(b, o, t, u, s, d + 1, sum);
}
const buf_eq = Buffer.from(" = ")
const buf_nl = Buffer.from("\n")
function term_nl(b, o, t, u, s, d, sum) {
  process.stdout.write(Buffer.concat([
    Buffer.from(sum[0].toString().padStart(3)), buf_eq, str.slice(0, d), buf_nl
  ]))
  return ok(b, o, t, u, s, d, sum);
}

function term_do_negate(b, o, t, u, s, d, sum) {
  return ok(b, o, t, u, s, d, [ -sum[0], sum[1] ]);
}

function term_do_bang(b, o, t, u, s, d, sum) {
  return ok(b, o, t, u, s, d, [ sum[0] ? 0 : 1, sum[1] ]);
}

function term_do_mul(b, o, t, u, s, d, sum) {
  return ok(b, o, t, u, s, d, [ sum[1][0] * sum[0], sum[1][1] ]);
}

function term_do_div(b, o, t, u, s, d, sum) {
  return sum[0] ? ok(b, o, t, u, s, d, [ (sum[1][0] / sum[0]) | 0, sum[1][1] ])
                : 0;
}

function term_do_plus(b, o, t, u, s, d, sum) {
  return ok(b, o, t, u, s, d, [ sum[1][0] + sum[0], sum[1][1] ]);
}

function term_do_minus(b, o, t, u, s, d, sum) {
  return ok(b, o, t, u, s, d, [ sum[1][0] - sum[0], sum[1][1] ]);
}

// Main function
function main() {
  let o = new Array(2048).fill(0);
  let s = 0;

  function D(S) { o[s++] = 1, o[s++] = S; }
  function B(b) { o[s++] = 2, o[s++] = eval(`term_${b}`); }
  function T(S) { o[s++] = 3, o[s++] = S; }

  // clang-format off
  D(0), T("expression"), B("nl");
  D("constant"), B("1");
  D("constant"), B("2");
  D("constant"), B("3");

  D("primary_expression"), T("constant");
  D("primary_expression"), B("open_paren"), T("expression"), B("close_paren");

  D("unary_expression"), T("primary_expression");
  D("unary_expression"), B("minus"), T("unary_expression"), B("do_negate");
  D("unary_expression"), B("bang"), T("unary_expression"), B("do_bang");

  D("multiplicative_expression"), T("unary_expression");
  D("multiplicative_expression"), T("multiplicative_expression"), B("mul"), T("unary_expression"), B("do_mul");
  D("multiplicative_expression"), T("multiplicative_expression"), B("div"), T("unary_expression"), B("do_div");

  D("additive_expression"), T("multiplicative_expression");
  D("additive_expression"), T("additive_expression"), B("plus"), T("multiplicative_expression"), B("do_plus");
  D("additive_expression"), T("additive_expression"), B("minus"), T("multiplicative_expression"), B("do_minus");

  D("expression"), T("additive_expression");
  o[s++] = 0;

  grow_toti_with_Yellow_pith(Rays.Pink, o, 0, null, s, 0, [0, 0]);
}

main();
