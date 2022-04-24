#include <stdio.h>
int arr[10];
void root(int root, int arr[]){
    if(arr[0] == '\0'){
        arr[0] = root;
    }else{
        printf("tree already has root");
    }
}
void set_left(int key, int parent){
    if(arr[parent] == '\0'){
        printf("No parent exists");
    }else{
        arr[2*parent+1] = key;
    }
}
void set_right(int key, int parent){
    if(arr[parent] == '\0'){
        printf("No parent exists");
    }else{
        arr[2*parent+2] = key;
    }
}
void display(){
    int i, size=10,sizes =10, j, k;
    for(j = 0; j < size; j++){
            printf(" ");
            size--;
    }
    printf("%c\n", arr[0]);
    size = 10;
    for (i = 0; i < 10; i++){
        for(j = 0; j < size; j++){
            printf(" ");
        }
        printf("%d", arr[2*i+1]);
        for(k = 0; k < sizes; k++){
            printf(" ");
        }
        printf("%d", arr[2*i+2]);
        size = size-1;
        sizes = sizes-3;
        printf("\n");
    }
    
}
int main(){
    root(7, arr);
    set_left(5, 0);
    set_right(6, 0);
    set_left(9, 1);
    set_right(90, 1);
    set_left(45, 2);
    set_right(23, 2);
    display();
}