#include<stdio.h>
#include "defs.h"

int main(int argc, char* argv[]) {
  Sample s = {10, 10.5};

  // typecasting the address of s to an array of bytes
  char* sptr = (char*) &s;
  printf("&s: %p\n", &s); // displays the address of the struct variable s
  printf("sptr: %p\n", sptr); // displays the base address i.e. the address of the first byte of the struct

  printf("&s.a: %p\n", &s.a);
  printf("sptr: %p\n", sptr);

  printf("&s.d: %p\n", &s.d);
  printf("sptr + 8: %p\n", sptr + 8);

  // viewing addresses of each byte
  for(int i = 0; i < sizeof(s); i++)
    printf("%p\n", sptr + i);
  return 0;
}
