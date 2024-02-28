#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum = 0;  // *ptr declares a pointer var

  printf("Enter number of elements: ");
  scanf("%d", &n);

  //ptr = (cast-type*) malloc(byte-size)
  ptr = (int*) malloc(n * sizeof(int)); // malloc(number of elements x byte-size)

  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements: ");
  for(i = 0; i < n; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  
  // deallocating the memory
  free(ptr);

  return 0;
}