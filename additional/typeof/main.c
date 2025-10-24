#include<stdio.h>

int main(int argc, char* argv[]) {

  typeof(int) a; // specifies variable a which is of type int
  a = 10;
  printf("a = %d\n", a);
  
  typeof('b') b; // same, the argument is an expression consisting of character constant which has the type int
  b = 0; // so, b is an int
  printf("b = %d\n", b);


  // declarations of pointers and arrays
  typeof(int*) p1, p2; // declares two int pointers p1, p2
  /* equivalent to:
     
     int *p1, *p2;
     
  */

  typeof(int) *p3, p4; // declares int pointer p3 and int p4
  /* equivalent to:

     int *p3, p4;
     
  */

  typeof(int[10]) a1, a2; // declares two arrays of integers
  /* equivalent to:

     int a1[10], a2[10];

  */

  extern int foo();

  /* if you use an expression with typeof, the expression is not evaluated. Only the type of that expression is
     derived.

     The following example declares the variable var of type int because the expression foo() is of type int.

     The function foo is not invoked because the expression is not evaluated. */
  typeof(foo()) var; // declares a variable named var of type int

  var = 100;
  printf("var = %d\n", var);

  int *x;

  typeof(*x) y;
  /*
    equivalent to:
    int y;

  */

  y = 120;
  printf("y = %d\n", y);
  
  return 0;
}
