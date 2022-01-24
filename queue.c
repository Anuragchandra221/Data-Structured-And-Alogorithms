#include<stdio.h>
int queue[20], front = -1, rear = -1, max_size;
void enqueue(){
    int x;
    if(rear==max_size-1){
        printf("Overflow");
    }else if(front==-1 && rear==-1){
        printf("Enter the element: ");
        scanf("%d", &x);
        rear = rear + 1;
        front = front + 1;
        queue[rear] = x;
    }else{
        printf("Enter the element: ");
        scanf("%d", &x);
        rear = rear + 1;
        queue[rear] = x;
    }
}
void dequeue(){
    if(front<rear){
        if(front==-1 && rear==-1){
            printf("underflow");
        }else if(front==rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
    }
}
void display(){
    int i;
     if(front==-1 && rear==-1){
        printf("There are no elements");
    }
    else if(front<=rear){
        for(i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }else{
        printf("There are no elements");
    }
}
int main(){
    int choice, run=1;
    printf("----------QUEUE-----------");
    printf("\nEnter the size of queue: ");
    scanf("%d", &max_size);
    while (run==1){
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
        case 5:
            printf("%d %d", front, rear);
        default:
            break;
        }
    }
    return 0;
}