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
void insertRandom();
void deleteRandom();
void search();
struct node *head;
int main(){
    int choice, run=1;
    while(run==1){
        printf("\n----------OPTIONS----------------\n");
        printf("1.Insert at the begining\n2.Insert at end\n3.Insert in a given location\n4.Delete from begining\n5.Delete from end\n6.Delete from a given position\n7.Search\n8.Display\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertRandom();
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteRandom();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            run = 0;
            break;
        default:
            printf("Invalid input");
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
void insertRandom(){
    struct node *ptr;
    int item, key;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        printf("Enter element to be searched: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head!=NULL){
            printf("Enter the key after which element has to be inserted: ");
            scanf("%d", &key);
            struct node *temp, *temp1;
            temp = head;
            while(temp->data != key){
                temp = temp->next;
            }
            temp1 = temp->next;
            temp->next = ptr;
            ptr->next = temp1;
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
void deleteRandom(){
    if(head!=NULL){
        struct node *ptr, *temp;
        ptr = head;
        int key;
        printf("Enter the key after which element has to be deleted: ");
        scanf("%d", &key);
        while(ptr->data != key){
            ptr = ptr->next;
        }
        if(ptr->data == key && ptr->next == NULL){
            printf("No next element");
        }else{
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }else{
        printf("No elements in linked list");
    }
}
void search(){
    if(head!=NULL){
        int item;
        printf("Enter the element to be searched: ");
        scanf("%d", &item);
        struct node *ptr;
        ptr = head;
        while(ptr->data != item && ptr->next != NULL){
            ptr = ptr->next;
        }
        if(ptr->data == item){
            printf("Element found");
        }else{
            printf("Element not found");
        }
    }else{
        printf("Linked list is empty");
    }
}