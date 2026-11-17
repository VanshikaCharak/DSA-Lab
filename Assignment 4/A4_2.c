// Write a program for deletion of a node at end, front and any index in a linked list.  
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
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    printf("Original linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    if(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    if(head!=NULL){
        temp=head;
        if(temp->next==NULL){
            free(temp);
            head=NULL;
        }else{
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
        }
    }
    printf("\nEnter position of node to delete: ");
    scanf("%d",&pos);
    if(head==NULL){
        printf("Linked list is empty");
    }else if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
    }else if(pos>1){
        temp=head;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL || temp->next==NULL){
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
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}