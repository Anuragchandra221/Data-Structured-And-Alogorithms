#include<stdio.h>
int a[10];

void heapify(int a[],int n,int i){
    
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    int temp;

    if (l < n && a[l] > a[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
 
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void buildHeap(int a[],int n){
    int lastLeaf = (n-1)/2 , i;
    int temp;
    for(i=lastLeaf; i>=0; i--){
        heapify(a, n, i);
    }
    for(i=n-1; i>0; i--){
        
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main(){
    int  n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    buildHeap(a, n);

    for ( i = 0; i < n; i++){
        printf("%d ", a[i]);
    }


    return 0;
}