#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int stack[20];
int top=-1;
void push(int x){
    top = top+1;
    stack[top] = x;
}
void pop(char x){
    if(top==-1){
        return;
    }else{
        int a = stack[top-1];
        int b = stack[top];
        top = top -1;
        if(x=='+'){
            stack[top] = a+b;
        }else if(x=='-'){
            stack[top] =  a-b;
        }else if(x=='*'){
            stack[top] =  a*b;
        }else{
            stack[top] =  a/b;
        }
    }
}
int main(){
    char exp[20];
    char *e;
    printf("Enter the expression: ");
    scanf("%s", &exp);
    e = exp;
    while(*e!='\0'){
        if(isalnum(*e)){
            push(*e-48);
        }else{
            pop(*e);
        }
        e++;
    }
    printf("%d", stack[top]);
}