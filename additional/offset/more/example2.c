#include<stdio.h>

typedef struct Sample {
  int a;
  int b;
} Sample;

int main(int argc, char* argv[]) {

  printf("%zu\n", (size_t) &((Sample*)0)->b);
  printf("%p\n", &((Sample*)0)->b);

  printf("%zu\n", (size_t) &((Sample*)1)->b);
  printf("%p\n", &((Sample*)1)->b);

  return 0;
}
