// Write a Program for insertion at end, front and at any index in linked list.  
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL,*temp,*newnode;
    int n,x,pos;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("Enter value to insert at start: ");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
    printf("Enter value to insert at end: ");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("Enter value to insert at a position: ");
    scanf("%d",&x);
    printf("Enter position: ");
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }else{
        temp=head;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Invalid position");
            free(newnode);
            return 0;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    temp=head;
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}