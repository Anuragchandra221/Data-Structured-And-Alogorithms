#include<stdio.h>
int main(){
    int a[10] = {2, 5, 4, 3, 7, 6};
    int element = 6;
    int beg=0, end=6;
    int mid=(beg+end)/2;
    while(beg<=end && a[mid]!=element){
        if(element<a[mid]){
            end = mid-1;
        }else{
            beg = mid+1;
        }
        mid = (beg+end)/2;
    }
    if(a[mid]==element){
        printf("Element found at position %d", mid);
    }else{
        printf("Element not found");
    }
    return 0;
}