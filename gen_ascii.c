#include <stdio.h>

const char *to_c_char_literal(int c) {
  // Static buffer to hold the literal string
  static char buf[8];

  switch (c) {
  case 7:
    return "'\\a'";
  case 8:
    return "'\\b'";
  case 9:
    return "'\\t'";
  case 10:
    return "'\\n'";
  case 11:
    return "'\\v'";
  case 12:
    return "'\\f'";
  case 13:
    return "'\\r'";
  case 92:
    return "'\\\\'";
  case 39:
    return "'\\\''";
  case 34:
    return "'\\\"'";
  case 63:
    return "'\\?'"; // avoid trigraphs
  default:
    if (c >= 32 && c <= 126 && c != 39 && c != 92) {
      snprintf(buf, sizeof(buf), "'%c'", c);
    } else {
      snprintf(buf, sizeof(buf), "'\\%03o'", c);
    }
    return buf;
  }
}

void gen_ascii(FILE *o, const char *b, void (*cb)(FILE *, const char *, int)) {
  fprintf(o, "#include\"common.h\"\n");
  fprintf(o, "#define C(I) Chapter(I) N(%s##I)\n", b);
  fprintf(o, "// clang-format off\n");
  for (int i = 0; i < 256; ++i) {
    fprintf(o, "C(%3d) /* %6s 0x%02X 0b%08b*/ {", i, to_c_char_literal(i), i,
            i),
        cb(o, b, i), fprintf(o, "}\n");
  }
}
