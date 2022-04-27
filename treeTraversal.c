#include<stdio.h>
char tree[]={'d', 'a', 'f', 'b', 'r', 't', 'g', 'q', '\0', '\0', 'v', 'j', 'l', '\0', '\0'};
int size = 15;
int getLeftChild(int index){
    if(tree[index]!='\0' && 2*index+1<=size){
        return 2*index+1;
    }
}
int getRightChild(int index){
    if(tree[index]!='\0' && 2*index+2<=size){
        return 2*index+2;
    }
}
void preorder(int index){
    if(index>=0 && tree[index] != '\0'){
        printf("%c ", tree[index]);
        preorder(getLeftChild(index));
        preorder(getRightChild(index));
    }
}
void inorder(int index){
    if(index>=0 && tree[index] != '\0'){
        inorder(getLeftChild(index));
        printf("%c ", tree[index]);
        inorder(getRightChild(index));
    }
}
void postorder(int index){
    if(index>=0 && tree[index] != '\0'){
        postorder(getLeftChild(index));
        postorder(getRightChild(index));
        printf("%c ", tree[index]);
    }
}
void main(){

    printf("Preorder:\n");
    preorder(0);
    printf("\nInorder\n");
    inorder(0);
    printf("\nPostorder:\n");
    postorder(0);

}