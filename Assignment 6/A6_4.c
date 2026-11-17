// Write a program to implement stack using linked list.  
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *top=NULL,*newnode,*temp;
    int choice,x;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
    do{
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&x);
            newnode->data=x;
            newnode->next=top;
            top=newnode;
        }else if(choice==2){
            if(top==NULL){
                printf("Stack is empty");
            }else{
                temp=top;
                printf("Deleted element: %d",top->data);
                top=top->next;
                free(temp);
            }
        }else if(choice==3){
            if(top==NULL){
                printf("Stack is empty");
            }else{
                temp=top;
                printf("Stack: ");
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
            }
        }else if(choice!=4){
            printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}