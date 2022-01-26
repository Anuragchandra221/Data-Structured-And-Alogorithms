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
void deleteBeg(){
    struct node *ptr;
    if(head==NULL){
        printf("No elements left");
    }else{
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
}
void insertEnd(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL){
        printf("Overflow");
    }else{
        printf("Enter element: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head==NULL){
            ptr->next = NULL;
            head = ptr;
        }else{
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = ptr;
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