#include<stdio.h>
int main(){
    int a[100], n, i, j, temp;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
        for(j=i; j>0; j--){
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0; i<n; i++){
        printf("%d  ", a[i]);
    }
    return 0;
}