#include "common.h"
void sophis3();
void gen_ascii(FILE *o, const char *b, void (*cb)(FILE *, const char *, int));

void cb(FILE *o, const char *b, int i) { //
  if (i < 0x80)
    fprintf(o, " 1, o[b](); ");
  else if (i < 0xE0)
    fprintf(o, " 2, o[b](); ");
  else if (i < 0xF0)
    fprintf(o, " 3, bo(); ");
  else if (i < 0xF8)
    fprintf(o, " 4, bo(); ");
  else
    fprintf(o, " 5, bo(); ");
}

int main() {
  sophis3();
  // gen_ascii(stdout, "utf8", cb);
  // fprintf(stdout, "\n");
}
