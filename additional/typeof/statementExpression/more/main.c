#include<stdio.h>

/*!
  \file main.c
  \brief Where statement expressions can be used.

  \details Statement expressions, like expressions, have a type, compute a value and can be used wherever
  expressions are accepted: declarations, initializers, expression statements, expressions, selection(\c if, \c switch)
  and iterations (\c while, \c do, \c for) statements, the \c return statements.

  An exception to this is that statement expressions have to be within a function or a block, no file scope
  statement expressions are allowed. So, the following program is incorrect:
  \code{.c}
  int a = ({1;}); // ERROR!
  inf foo(void) {
      return a;
  }
  \endcode

  A statement expression has type \c void if the last statement is not an expression that returns a value.
  The statement at line 32 is of type \c void because it ends with a declaration. But it will be invalid it is used as an rvalue. But the statement at line 34 is of type \c int because it ends with the statement \c a \c = \c 1; where \c a is of type \c int

  \example example1.c
  If a statement expression ends with an expression, the type and value are determined by the final expression i.e the expression with which the statement expression ended. So, in this program, the return type of the statement expression is actually a \c float because the final expression of the statement expression is:
  \code{.c}
  (float)a / b;
  \endcode
 */

int main(int argc, char *argv[]) {

  ({int b = 10;});

  int val = ({int a; a = 1;});

  return 0;
}
