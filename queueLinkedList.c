#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node{
    int data;
    struct node *next;
};
struct node *head;
int main(){
    int choice, run=1;
    while(run==1){
        printf("\nOptions\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            run=0;
            break;
        default:
            break;
        }
    }
}
void enqueue(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL){
        printf("Overflow");
    }else{
        printf("Enter the element: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head==NULL){
            ptr->next = NULL;
            head = ptr;
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}
void dequeue(){
    struct node *ptr;
    if(head==NULL){
        printf("Underflow");
    }else{
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
}
void display(){
    struct node *ptr;
    ptr = head;
    if(head==NULL){
        printf("There are no elements");
    }
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}