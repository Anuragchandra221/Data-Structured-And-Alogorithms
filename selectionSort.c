#include<stdio.h>
int main(){
    int a[100], n, i, j, temp, min, loc;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for ( i = 0; i < n; i++){
        temp = a[i];
        min = a[i+1];
        for(j=(i+1); j<n; j++){
            if(a[j] < min){
                min = a[j];
                loc = j;
            }
        }
        if(min < temp){
            a[i] = min;
            a[loc] = temp;
        }
    }
    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d", a[i]);
    }
    return 0;
}