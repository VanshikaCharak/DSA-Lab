// Write a program for deletion at start, at end and at any point in a circular linked list.  
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

struct Node* delFront(struct Node* head){
    struct Node* ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    free(head);
    head=ptr->next;
    return head;

}
struct Node* delEnd(struct Node* head){
    struct Node* ptr=head;
    while(ptr->next->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head;
    free(head);
    head=ptr->next;
    return head;
}
struct Node* anyPos(struct Node* head,int pos){
    if(pos==1){
        delFront(head);
    }
    struct Node* ptr=head;
    struct Node* start=head;
    for(int i=1;i<(pos-1);i++){
        ptr=ptr->next;
    }
    struct Node* toDel=ptr->next;
    ptr->next=toDel->next;
    free(toDel);
    head=start;
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
    printf("DELETE FRONT:\n");
    head=delFront(head);
    display(head);
    printf("DELETE END:\n");
    head=delEnd(head);
    display(head);
    printf("DELETE Position: ");
    int pos;
    scanf("%d",&pos);
    head=anyPos(head,pos);
    display(head);

    return 0;
}