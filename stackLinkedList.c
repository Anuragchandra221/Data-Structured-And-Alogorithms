#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void push();
void pop();
void display();
int main(){
    int choice, run=1;
    while (run==1){
        printf("\nOptions\n1. Push 2. Pop 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            run=0;
        default:
            break;
        }
    }
    return 0;
}
void push(){
    int item;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL){
        printf("Overflow");
    }else{
        printf("Enter the element: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head!=NULL){
            ptr->next = head;
            head = ptr; 
        }else{
            head = ptr;
            ptr->next = NULL;
        }
    }
}
void pop(){
    if(head!=NULL){
        struct node* ptr;
        ptr = head;
        printf("Deleted %d", head->data);
        head = ptr->next;
        free(ptr);
    }else{
        printf("Underflow");
    }
}
void display(){
    if(head!=NULL){
        struct node *ptr;
        ptr = head;
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else{
        printf("Stack is empty");
    }
}