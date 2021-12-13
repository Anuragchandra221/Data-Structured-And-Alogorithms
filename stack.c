#include<stdio.h>
int stack[20];
int top=-1, max;
void push(){
    if(top<max-1){
        printf("Enter element: ");
        top = top+1;
        scanf("%d", &stack[top]);
    }else{
        printf("Stack Overflow");
    }
}
void pop(){
    if(top!=-1){
        printf("Deleted element %d \n", stack[top]);
        top = top - 1;
    }else{
        printf("Stack Underflow");
    }
}
void display(){
    int i = top;
    if(top==-1){
        printf("Stack Underflow");
    }else{
        while(i!=-1){
            printf("%d\n", stack[i]);
            i = i-1;
        }
    }
}
int main(){
    int choice, run=1;
    printf("----------STACK-----------");
    printf("\nEnter the size of stack: ");
    scanf("%d", &max);
    while (run==1){
        printf("\nOptions\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
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