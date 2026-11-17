// Write a program to implement stack using array. 
#include <stdio.h>
#define size 100

int main(){
    int stack[size],top=-1,choice,x;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            if(top==size-1){
                printf("Stack is full");
            }else{
                printf("Enter data: ");
                scanf("%d",&x);
                stack[++top]=x;
            }
        }else if(choice==2){
            if(top==-1){
                printf("Stack is empty");
            }else{
                printf("Deleted element: %d\n",stack[top]);
                top--;
            }
        }else if(choice==3){
            if(top==-1){
                printf("Stack is empty");
            }else{
                printf("Stack: ");
                for(int i=top;i>=0;i--){
                    printf("%d ",stack[i]);
                }
                printf("\n");
            }
        }else if(choice!=4){
            printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}