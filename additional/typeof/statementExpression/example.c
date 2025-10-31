/*!
  \file example.c

  This program demonstrates how the macro \ref "maxInt(a, b)" does <em>variable shadowing</em>

  Variable shadowing occurs when a variable declared in an inner scope takes precedence over a variable
  with the same name declared in an outer scope.

  Look at line 27. If we expand the call to the macro at that line, then this is what we get:

  \code{.c}
  int c = ({
  int _a = _a; // _a is actually the local variable here
  int _b = _b; // same with _b, hence both initially store garbage value
  _a > _b ? _a : _b; // so, garbage is returned. GIGO
  });
  \endcode
 */

#include "defs.h"
#include<stdio.h>

int main(int argc, char *argv[]) {

  int _a = 1, _b = 2;

  int c = maxInt(_a, _b);

  printf("Max: %d\n", c);
  return 0;
}
