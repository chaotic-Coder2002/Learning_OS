#include<stdio.h>
#include<string.h>
#include "defs.h"

/*!
  \file main.c
  \brief An example demonstrating the working of the \c offsetof macro.

  The \c offsetof macro in C basically returns the offset of a structure member from the beginning of that structure.

  Here, the \c size_t is an unsigned integer type used for a count of bytes. So, the following line:
  \code{.c}
  unsigned int offset = (size_t) &((Sample*)NULL)->d;
  \endcode
  actually returns the offset of the field \c d from the beginning of \c Sample in bytes.

  The above line has been explored in details in the given example programs.

  The above line can also be written like this:
  \code{.c}
  unsigned int offset = (size_t) &((Sample*)0)->d;
  \endcode
  They both mean the same. See <a href="https://stackoverflow.com/a/13723512">here</a>.

  \example example1.c
  This is an example supporting <a href="https://stackoverflow.com/a/713970">this answer</a> in StackOverflow.

  In the line \c unsigned \c int \c offset \c = \c (\c size_t) \c &s->d, the \c -> operator is not used to
  access the value of the field \c d, it's instead used to access its address. So, here we cannot say that the
  we are dereferencing the \c Sample pointer \c s. So, since no dereferencing is happening here,
  the following lines are valid as well:
  \code {.c}
  Sample *s2 = NULL;
  double *dptr = &s2->d;
  \endcode

  Now, if \c s2 is \c NULL, then how do we get an address of its field \c d ? I think <a href="https://stackoverflow.com/a/35135814">this</a> could be the answer to that question.
 */

int main(int argc, char* argv[]) {
  Sample s;

  unsigned int offset = (size_t) &((Sample*)NULL)->d;
  printf("%u\n", offset);

  double *dptr = &((Sample*)NULL)->d;
  printf("%p\n", dptr);

  double *dptr2 = &s.d;
  printf("%p\n", dptr2);
  
  return 0;
}
