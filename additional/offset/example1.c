#include<stdio.h>
#include<stdlib.h>
#include "defs.h"

int main(int argc, char *argv[]) {
  Sample *s = malloc(sizeof(Sample));

  unsigned int offset = (size_t) &s->d;
  printf("%u\n", offset);

  double *dptr = &s->d;
  printf("%p\n", dptr);

  Sample *s2 = NULL;

  offset = (size_t) &s2->d;
  printf("%u\n", offset);

  double *dptr2 = &s2->d;
  printf("%p\n", dptr2);

  free(s);
  
  return 0;
}
