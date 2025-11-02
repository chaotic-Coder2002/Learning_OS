#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "defs.h"

/*!
  \file main.c
  \example example1.c
  In this example, the macro \c FINDMAX is called by passing expressions rather than variables as arguments.
  After argument substitution, the expressions which are specified as macro parameters are evaluated only once.
  That is achieved by using local variables inside the macro definition.
  The macro invocation:
  \code{.c}
  FINDMAX(max, ++temp, --size);
  \endcode
  actually looks like this after macro substitution:
  \code{.c}
  typeof((++v)[0])) * _v = ++v; // this is where the incrementation happens
  typeof(--n) _n = --n; // this is where the decrementation happens

  // and so on...
  \endcode
  Without local copies of macro parameters, they would be evaluated in every iteration of the \c for loop
 */

int main(int argc, char *argv[]) {

  srand(time(NULL));

  int size;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  for(int i = 0; i < size; i++) {
    arr[i] = rand() % size + 1;
    printf("%d ", arr[i]);
  }
  puts("");

  int max;

  FINDMAX(max, arr, size);

  printf("Max: %d\n", max);
  return 0;
}
