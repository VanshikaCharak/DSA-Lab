// Given a string containing just the characters ’(’ and ’)’, return the length of the longest valid (wellformed) parentheses substring. Also print all the invalid parenthesis and space complexity of the code(max top height of the stack)
#include <stdio.h>

int top=-1;
void push(char stack[100],char a,int len){
    if (top==len-1){
        printf("Stack overflow");
        return;
    }
    stack[++top]=a;
}
char pop(char stack[100]){
    if (top==-1){
        printf("Stack Underflow");
        return 0;
    }
    char ret=stack[top];
    top--;
    return ret;
}

int main(){
    char arr[100];
    char stack[100];
    int len;
    printf("Enter length of string: ");
    scanf("%d",&len);
    printf("Enter string: ");
    scanf("%s",arr);
    int topmax=-1;
    int maxlen=0;
    int strlen=0;
    printf("Invalid Parenthesis are: ");
    for (int i=0;i<len;i++){
        if(arr[i]=='('&&(top==-1||stack[top]!='(')){
            push(stack, arr[i], len);
            ++strlen;
        }
        else if(arr[i]==')'&&top!=-1&&stack[top]=='('){
            pop(stack);
            ++strlen;
        }
        else{
            printf("%c ",arr[i]);
            strlen=0;
        }
        if(top>topmax){
            topmax=top;
        }
        if(strlen>maxlen){
            maxlen=strlen;
        }
    }
    while(top!=-1){
        char invalid=pop(stack);
        printf("%c ",invalid);
    }
    printf("\nSpace complexity: %d",topmax+2);
    printf("\nMaximum substring length: %d",maxlen);
    return 0;
}