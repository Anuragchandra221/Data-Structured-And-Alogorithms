#include<stdio.h>
#include<stdlib.h>
struct node{
    int exp;
    float coeff;
    struct node *next;
};
struct node *heada;
struct node *headb;
struct node *headc;

void insertCoeffA(int i);
void insertCoeffB(int i);
void insertCoeffC(float a, float b, int i);

void add();
void display();
void delete();

float getCoeffA(int i); 
float getCoeffB(int i); 

int main(){
    int run=1, choice;
    while(run==1){
        add();
        while(heada!=NULL && headb!=NULL && headc!=NULL){
            delete();
        }
        printf("\nIf you don't want to continue press 0: ");
        scanf("%d", &choice);
        if(choice == 0){
            run = 0;        
        }
    }
    return 0;
}

void add(){
    int i, deg1, deg2, j;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);
    for(i=0; i<deg1+1; i++){
        printf("Enter the coefficient of x^%d: ", i);
        insertCoeffA(i);
    }
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &deg2);
    for(i=0; i<deg2+1; i++){
        printf("Enter the coefficient of x^%d: ", i);
        insertCoeffB(i);
    }
    if(deg1<=deg2){
        for(i=0; i<deg1+1; i++){
            insertCoeffC(getCoeffA(i), getCoeffB(i), i);
        }
        if(deg1!=deg2){
            for(i=deg1+1; i<deg2+1; i++){
                insertCoeffC(0, getCoeffB(i), i);
            }
        }
    }else{
        for(i=0; i<deg2+1; i++){
            insertCoeffC(getCoeffA(i), getCoeffB(i), i);
        }
        if(deg1!=deg2){
            for(i=deg2+1; i<deg1+1; i++){
                insertCoeffC(getCoeffA(i), 0, i);
            }
        }
    }
    display();
}

void insertCoeffA(int i){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        scanf("%d", &item);
        ptr->coeff = item;
        ptr->exp = i;
        if(heada!=NULL){
            struct node *temp;
            temp = heada;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }else{
            heada = ptr;
            ptr->next = NULL;
        }
    }
}

void insertCoeffB(int i){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        scanf("%d", &item);
        ptr->coeff = item;
        ptr->exp = i;
        if(headb!=NULL){
            struct node *temp;
            temp = headb;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }else{
            headb = ptr;
            ptr->next = NULL;
        }
    }
}

void insertCoeffC(float a, float b, int i){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        ptr->coeff = a+b;
        ptr->exp = i;
        if(headc!=NULL){
            struct node *temp;
            temp = headc;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }else{
            headc = ptr;
            ptr->next = NULL;
        }
    }
}

float getCoeffA(int i){
    if(heada!=NULL){
        int itm;
        struct node *ptr;
        ptr = heada;
        while(ptr->exp!=i && ptr->next!=NULL){
            ptr = ptr->next;
        }
        if(ptr->exp==i){
            return ptr->coeff;
        }else{
            printf("Not found");
        }
    }
}

float getCoeffB(int i){
    if(headb!=NULL){
        int itm;
        struct node *ptr;
        ptr = headb;
        while(ptr->exp!=i && ptr->next!=NULL){
            ptr = ptr->next;
        }
        if(ptr->exp==i){
            return ptr->coeff;
        }else{
            printf("Not found");
        }
    }
}

void display(){
    if(headc!=NULL){
        struct node *ptr;
        ptr = headc;
        while(ptr!=NULL){
            printf("%.2f x^%d", ptr->coeff, ptr->exp);
            if(ptr->next != NULL){
                printf(" + ");
            }
            ptr = ptr->next;
        }
    }else{
        printf("Empty");
    }
}

void delete(){
    struct node *ptra, *ptrb, *ptrc;

    ptra = heada;
    heada = ptra->next;
    free(ptra);

    ptrb = headb;
    headb = ptrb->next;
    free(ptrb);

    ptrc = headc;
    headc = ptrc->next;
    free(ptrc);

}