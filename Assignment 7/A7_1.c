// Given a string containing just the characters ’(’ and ’)’, return the length of the longest valid (wellformed) parentheses substring.  
#include <stdio.h>

int validity(char arr[],int n){
    int stack[n];
    int top=-1;
    int maxlen=0;
    stack[++top]=-1;
    for(int i=0;i<n;i++){
        if(arr[i]=='('){
            stack[++top]=i;
        }
        else{
            top--;
            if(top==-1){
                stack[++top]=i;
            }
            else {
                int len=i-stack[top];
                if (len>maxlen) {
                    maxlen=len;
                }
            }
        }
    }
    return maxlen;


}

int main(){
    char arr[100];
    int len;
    printf("Enter length of string: ");
    scanf("%d",&len);
    printf("Enter string: ");
    scanf("%s",&arr);
    int maxlen=validity(arr,len);
    printf("Maximum substring length is: %d",maxlen);
    return 0;
}