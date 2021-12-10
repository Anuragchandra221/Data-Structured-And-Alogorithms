#include<stdio.h>
int main(){
    int a[100], i, top=-1, max=6;
    //push operation
    printf("Enter elements: ");
    while (top<max-1){
        top = top+1;
        scanf("%d", &a[top]);
    }
    printf("The elements of the array is: ");
    for(i=0; i<max; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    //pop operation
    while (top!=-1){
        printf("Deleted a[%d] %d \n",top ,a[top]);
        top = top -1;
    }
    return 0;
}