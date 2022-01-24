#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};
void insertBeg();
void display();
struct node *head;
int main(){
    int choice, run=1;
    while(run==1){
        printf("\n----------OPTIONS----------------\n");
        printf("1.Insert at the begining\n2.Display\n3.Insert at end\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            insertBeg();
            break;
        case 2:
            display();
            break;
        case 3:
            insertEnd();
            break;
        default:
            run=0;
        }
    }
}
void insertBeg(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        printf("Enter the element: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
    }
}
void display(){
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL){
        printf("%d", ptr->data);
        if(ptr->next != NULL){
            printf("--->");
        }
        ptr = ptr->next;
    }
}