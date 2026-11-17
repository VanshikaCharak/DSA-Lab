// Implement the algorithm of converting Infix to Postfix expression. You need to consider ’(’, ’)’, ’+’, ’-’,
// ’/’, ’*’, ’%’, and ˆ characters in your expression.  
#include <stdio.h>
#include <ctype.h>

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }else if(ch=='*'||ch=='/'||ch=='%'){
        return 2;
    }else if(ch=='+'||ch=='-'){
        return 1;
    }
    return 0;
}
int main(){
    char infix[100],postfix[100],stack[100];
    int top=-1,k=0;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[k++]=infix[i];
        }else if(infix[i]=='('){
            stack[++top]=infix[i];
        }else if(infix[i]==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[k++]=stack[top--];
            }
            if(top!=-1){
                top--;
            }
        }else{
            while(top!=-1&&stack[top]!='('&&(precedence(stack[top])>precedence(infix[i])||(precedence(stack[top])==precedence(infix[i])&&infix[i]!='^'))){
                postfix[k++]=stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    while(top!=-1){
        postfix[k++]=stack[top--];
    }
    postfix[k]='\0';
    printf("Postfix expression: %s",postfix);
    return 0;
}