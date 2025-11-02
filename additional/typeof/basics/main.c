#include<stdio.h>

/*!
  \file main.c
  \brief The \c typeof operator

  \details This program simply declares two variables \c a and \c b of type \c int and \c char
  respectively.

  \example example1.c
  An example showing the declaration of pointers and
  arrays.

  \example example2.c
  If you use an expression with \c typeof, the expression is not evaluated. Only the type of that expression is
  derived.
 */


int main(int argc, char* argv[]) {

  typeof(int) a; // equivalent to- int a;
  typeof('b') b; // equivalent to- char b;
  
  return 0;
}
