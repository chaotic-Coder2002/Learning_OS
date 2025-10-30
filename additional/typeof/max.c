#include<stdio.h>

/* macro for finding the maximum element from an array */

#define FINDMAX(m, x, n)\
  { /* this indicates a scope */\
    typeof((x)[0]) * _x = x; /* creating a pointer to a type */		\
    typeof((m)) _m = _x[0]; /* assigning the element at the 0th index to _m */ \
    typeof((n)) _n = n;							\
    int i;								\
    for(i = 0; i < _n; i++)						\
      if(_x[i] > _m)							\
	_m = _x[i];							\
    m = _m;								\
  }
  

int main(int argc, char* argv[]) {

  int n;

  printf("enter size of the array: ");
  scanf("%d", &n);

  int arr[n];

  puts("enter elements into the array:");
  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);

  puts("The array is:");
  for(int i = 0; i < n; i++)
    printf("%d ", *(arr + i));

  int max;

  FINDMAX(max, arr, n)

  printf("\nThe largest element is: %d\n", max);

  return 0;
}
