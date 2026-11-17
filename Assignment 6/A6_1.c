// Write a program to reverse a doubly linked list.  
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

int main(){
    struct node *head=NULL,*temp,*newnode,*current,*nextnode;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    temp=head;
    printf("Original linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    current=head;
    while(current!=NULL){
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        head=current;
        current=nextnode;
    }
    temp=head;
    printf("\nReversed linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}