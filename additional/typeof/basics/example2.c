#include<stdio.h>

/*!
  \file example2.c
  \details In this program, we are basically declaring a variable \c var of type \c int because
  the expression \c foo() is of type \c int.
 */

/*!
  \fn int foo()
  \brief Just a sample function.
 */
int foo() {
  return 0;
}

int main(int argc, char* argv[]) {

  typeof(foo()) var; // basically this means int var;
  return 0;
}
