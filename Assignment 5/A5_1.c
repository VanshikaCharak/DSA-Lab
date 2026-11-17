// Write a program for insertion at start, at end and at any point in a circular linked list. 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* insert(struct Node* head,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        head=newNode;
        newNode->data=val;
        newNode->next=head;
    }
    else{
        struct Node* ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        newNode->data=val;
        ptr->next=newNode;
        newNode->next=head;
    }
    return head;
}

struct Node* insertFront(struct Node* head,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    struct Node* ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    head=newNode;
    return head;
}

struct Node* insertEnd(struct Node* head,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    struct Node* ptr=head;
    if(ptr==NULL){
        insertFront(head,val);
    }
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=head;

    return head;
}

struct Node* anyPos(struct Node* head,int val,int pos){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    struct Node* ptr=head;
    if(ptr==NULL){
        insertFront(head,val);
    }
    for(int i=1;i<(pos-1);i++){
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;

    return head;
}

void display(struct Node* head){
    struct Node* temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("End\n");
}
int main(){
    struct Node* head=NULL;
    int n;
    printf("enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter elements: \n");
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        head=insert(head,k);
    }
    display(head);
    printf("INSERT FRONT: ");
    int f;
    scanf("%d",&f);
    head=insertFront(head,f);
    display(head);
    printf("INSERT END: ");
    int l;
    scanf("%d",&l);
    head=insertEnd(head,l);
    display(head);
    printf("INSERT Element and Position: ");
    int pos,ele;
    scanf("%d %d",&ele,&pos);
    head=anyPos(head,ele,pos);
    display(head);

    return 0;
}