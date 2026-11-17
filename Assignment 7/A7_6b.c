// Implementing Queue using Linked List 
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *front=NULL,*rear=NULL,*newnode,*temp;
    int choice,x;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&x);
            newnode->data=x;
            newnode->next=NULL;
            if(rear==NULL){
                front=newnode;
                rear=newnode;
            }else{
                rear->next=newnode;
                rear=newnode;
            }
        }else if(choice==2){
            if(front==NULL){
                printf("Queue is empty");
            }else{
                temp=front;
                printf("Deleted element: %d\n",front->data);
                front=front->next;
                if(front==NULL){
                    rear=NULL;
                }
                free(temp);
            }
        }else if(choice==3){
            if(front==NULL){
                printf("Queue is empty");
            }else{
                temp=front;
                printf("Queue: ");
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
            }
        }else if(choice!=4){
            printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}