// Write a program for deletion in a Circular Linked List.  
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL,*temp,*newnode,*prev;
    int n,pos;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            temp=newnode;
        }else{
            temp->next=newnode;
            newnode->next=head;
            temp=newnode;
        }
    }
    temp=head;
    printf("Original linked list: ");
    if(head!=NULL){
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
    printf("\nEnter position of node to delete: ");
    scanf("%d",&pos);
    if(head==NULL){
        printf("Linked list is empty");
    }else if(pos==1){
        temp=head;
        if(head->next==head){
            head=NULL;
            free(temp);
        }else{
            while(temp->next!=head){
                temp=temp->next;
            }
            prev=head;
            head=head->next;
            temp->next=head;
            free(prev);
        }
    }else if(pos>1){
        temp=head;
        for(int i=1;i<pos-1 && temp->next!=head;i++){
            temp=temp->next;
        }
        if(temp->next==head){
            printf("Invalid position");
        }else{
            prev=temp->next;
            temp->next=prev->next;
            free(prev);
        }
    }else{
        printf("Invalid position");
    }
    temp=head;
    printf("Final linked list: ");
    if(head!=NULL){
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
    return 0;
}