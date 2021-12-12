#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x){
    top = top+1;
    stack[top] = x;
}
char pop(){
    if (top==-1){
        return -1;
    }else{
        return stack[top--];
    }
}
int precedence(char x){
    if(x=='('){
        return 0;
    }else if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
}
int main(){
    char exp[20], x;
    int i=0;
    char *e;
    printf("Enter the expression: ");
    scanf("%s", &exp);
    e=exp;
    while(*e!='\0'){
        if(isalnum(*e)){
            printf("%c", *e);
        }else if (*e=='('){
            push(*e);
        }else if(*e==')'){
            while((x=pop())!='(' && top>-1){
                printf("%c", x);
            }
        }else{
            while(precedence(stack[top])>=precedence(*e)){
                printf("%c", pop());
            }
            push(*e);
        }
        e=e+1;
    }while(top!=-1){
        printf("%c", pop());
    }
}