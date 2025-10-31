/*!
  \file statementExpTest.c
  \author chaotic-Coder2002
  \date 2025-10-31
 */

#include "defs.h"
#include<stdio.h>

int main(int argc, char* argv[]) {

  int mx = max(10, 30);

  printf("Max val: %d\n", mx);

  mx = maxInt(40, 20);
  printf("Max val: %d\n", mx);
  return 0;
}
