/**
   Statement expressions
 */

#include<stdio.h>

int main(int argc, char *argv[]) {
  /* A compound statement enclosed within parentheses may appear as an expression in GNU C.
   This allows us to use loops, switches and local variables an expression. */

  /* We know that, in general, a compound statement is a sequence of statements enclosed within braces. In the
     following construct, parentheses go around the braces. */
  
  int val = ({int y = -100; int z;
    if(y > 0) z = y;
    else z = -y;
    z; }); // the last thing in the compound statement should be an expression followed by a semicolon (look at `z;`)

  printf("val = %d\n", val);
  return 0;
}
