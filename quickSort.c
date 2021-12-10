#include<stdio.h>
int a[10] = {7, 2, 3, 12, 32};
int n = 5;
int partition(int low, int high){
    int i, j, pivot, temp;
    i = low;
    j = high;
    pivot = a[low];
    while(i<=j){
        while(a[i] <= pivot && i<n){
            i++;
        }
        while(a[j] > pivot && j>=0){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }else{
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
        }
    }
    return j;
}
void quick(int low, int high){
    if (low<high){
        int mid = partition(low, high);
        quick(low, mid-1);
        quick(mid+1, high);
    }
    
}
void main(){
    quick(0, n-1);
    for(int i = 0; i<5; i++){
        printf("%d ", a[i]);
    }
}