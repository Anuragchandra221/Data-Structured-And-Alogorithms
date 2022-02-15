#include <stdio.h>
int main(){
  int array[100], n, i, j, temp;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  printf("Enter elements:");
  for (i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  for (i = 0 ; i < n - 1; i++){
    for (j = 0 ; j < n - i - 1; j++){
      if (array[j] > array[j+1]) /* For decreasing order use '<' instead of '>' */{
        temp       = array[j+1];
        array[j+1]   = array[j];
        array[j] = temp;
      }
    }
  }
  printf("Sorted array is:\n");
  for (i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  return 0;
}