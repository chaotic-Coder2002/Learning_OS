#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "defs.h"

int main(int argc, char* argv[]) {
  srand(time(NULL));

  int max;

  int size = 10;

  int vec[size];

  for(int i = 0; i < size; i++) {
    vec[i] = rand() % 26 + 5; // random numbers between 5 and 30
    printf("%d ", vec[i]);
  }
  puts("");

  int *temp = vec;

  FINDMAX(max, ++temp, --size);

  printf("Max: %d\n", max);

  return 0;
}
