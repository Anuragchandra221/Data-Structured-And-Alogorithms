#include<stdio.h>
int queue[20], front = 0, rear = -1, max_size;
void enqueue(){
    int item;
    if(rear<max_size-1){
        printf("Enter the element: ");
        scanf("%d", &item);
        rear = rear+1;
        queue[rear] = item;
    }else{
        printf("\nOverflow\n");
    }
}
void dequeue(){
    if(rear!=-1 && front<=rear){
        if(front==rear){
            printf("Deleted %d", queue[front]);
            front = 0;
            rear = -1;
        }else{
            printf("Deleted %d", queue[front]);
            front = front + 1;
        }
    }else{
        printf("\nUnderflow\n");
    }
}
void display(){
    int i;
    if(rear!=-1 && front<=rear){
        for(i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }else{
        printf("\nQueue is empty\n");
    }
}
int main(){
    int choice, run=1;
    printf("----------QUEUE-----------");
    printf("\nEnter the size of queue: ");
    scanf("%d", &max_size);
    while (run==1){
        printf("\nQUEUE OPERATIONS\n1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
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
            printf("Invalid input");
            break;
        }
    }
    return 0;
}