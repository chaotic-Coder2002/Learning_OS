#include<stdio.h>


int main(int argc, char* argv[]) {
  printf("%f\n", ({int a = 10, b = 30; (float)a / b;}));
  return 0;
}
