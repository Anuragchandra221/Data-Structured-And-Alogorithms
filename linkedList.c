#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};
void insertBeg();
void display();
void deleteBeg();
void insertEnd();
void deleteEnd();
struct node *head;
int main(){
    int choice, run=1;
    while(run==1){
        printf("\n----------OPTIONS----------------\n");
        printf("1.Insert at the begining\n2.Display\n3.Insert at end\n4.Delete from begining\n5.Delete from end\n");
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
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        default:
            run=0;
        }
    }
}
void insertBeg(){
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
void display(){
    if(head!=NULL){
        struct node *ptr;
        ptr = head;
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            if(ptr->next != NULL){
                printf("--->");
            }
            ptr = ptr->next;
        }
    }
    else{
        printf("Linked list is empty");
    }
}
void deleteBeg(){
    if(head!=NULL){
        struct node* ptr;
        ptr = head;
        head = ptr->next;
        free(ptr);
    }else{
        printf("No elements in linked list");
    }
}
void insertEnd(){
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
void deleteEnd(){
    struct node *ptr, *temp;
    if(head==NULL){
        printf("No elements");
    }else if(head->next == NULL){
        head = NULL;
        free(head);
    }else{
        ptr = head;
        while(ptr->next!=NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
}