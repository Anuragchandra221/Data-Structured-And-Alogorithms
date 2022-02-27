#include<stdio.h>
void insert();
void delete();
void display();
int  max_size=10, hash[10];
int main(){
    int i, run=1, choice;
    for (i = 0; i < 10; i++){
        hash[i] = -1;
    }
    
    while (run==1){
        printf("\nQUEUE OPERATIONS\n1. Insert 2. Delete 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            run=0;
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
}
void insert(){
    int key, index;
    printf("Enter element to be inserted: ");
    scanf("%d", &key);
    index = (key % 10);
    while(hash[index] != -1){
        index = (index + 1) % 10;
    }
    if(hash[index] == -1){
        hash[index] = key;
    }
}
void display(){
    int i;
    for(i=0; i<10; i++){
        printf("%d at %d \n", hash[i], i);
    }
}
void delete(){
    int key, index;
    printf("Enter element to be deleted: ");
    scanf("%d", &key);
    index = (key % 10);
    while(hash[index] != key){
        index = (index + 1) % 10;
    }
    if(hash[index] == key){
        hash[index] = -1;
    }
}