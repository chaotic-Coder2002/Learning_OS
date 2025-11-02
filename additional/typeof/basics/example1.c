#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*!
  \file example1.c
  \details This program demonstrates how the \c typeof operator is used to declare pointers and
  arrays.
 */

int main(int argc, char* argv[]) {

  srand(time(NULL));

  int a = 10;

  typeof(int *) p1, p2; // int pointers

  p1 = &a;
  p2 = p1;

  typeof(int) *p3, p4; // int pointer p3 and an int p4

  p3 = calloc(5, sizeof(int)); // allocating memory space to p3
  for(int i = 0; i < 5; i++) {
    p3[i] = rand() % 5 + 1; // generate random numbers in the range [1, 5]
    printf("%d ", p3[i]);
  }

  p4 = 12 * p3[3];

  free(p3);

  printf("\np4 = %d\n", p4);

  typeof(int[10]) a1, a2; // declares two arrays a1 and a2 that can hold 10 integers each

  typeof(char* const) p = "Hello world"; // declares a const qualified char pointer p which means it can't be modified


  return 0;
}
