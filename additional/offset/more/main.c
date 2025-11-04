#include<stdio.h>
#include "defs.h"

int main(int argc, char* argv[]) {

  Tree aTree = {"Mango", {5, 2}};

  printf("sizeof(Nest): %zu\n", sizeof(Nest));
  printf("sizeof(Tree): %zu\n", sizeof(aTree));

  char* nestedStruct = (char*) &aTree.birdNest;

  Tree *temp = (Tree*)(nestedStruct - (size_t) &((Tree*)0)->birdNest);

  printf("sizeof(*temp): %zu\n", sizeof(*temp));
  
  return 0;
}
