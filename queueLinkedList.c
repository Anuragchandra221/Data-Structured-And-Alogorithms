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
        printf("\nOptions\n1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
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
            printf("Invalid option");
            break;
        }
    }
}
void enqueue(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL){
        printf("Overflow");
    }else{
        printf("Enter the element: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head!=NULL){
            struct node *temp;
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }else{
            head = ptr;
            ptr->next = NULL;
        }
    }
}
void dequeue(){
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
        printf("Queue is empty");
    }
}