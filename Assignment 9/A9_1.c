// Problem 1: Top View
// Given a pointer to the root of a binary tree, print the top view of the binary tree. The tree as seen from the top the nodes, is called the top view of the tree.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct queue{
    struct node *ptr;
    int hd;
};

struct node* tree(){
    int data;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct node *root=createNode(data);
    printf("Enter left child of %d:\n",data);
    root->left=tree();
    printf("Enter right child of %d:\n",data);
    root->right=tree();
    return root;
}

void top(struct node* root){
    if(root==NULL){
        return;
    }
    int front=0,rear=0;
    struct queue q[1000];
    int ans[2000],visited[2000]={0};
    int offset=1000;
    int min=0,max=0;
    q[rear].ptr=root;
    q[rear].hd=0;
    rear++;
    while(front<rear){
        struct queue temp=q[front];
        front++;
        struct node *curr=temp.ptr;
        int hd=temp.hd;
        if(visited[hd+offset]==0){
            ans[hd+offset]=curr->val;
            visited[hd+offset]=1;
        }
        if(hd<min){
            min=hd;
        }
        if(hd>max){
            max=hd;
        }
        if(curr->left!=NULL){
            q[rear].ptr=curr->left;
            q[rear].hd=hd-1;
            rear++;
        }
        if(curr->right!=NULL){
            q[rear].ptr=curr->right;
            q[rear].hd=hd+1;
            rear++;
        }
    }
    for(int i=min;i<=max;i++){
        if(visited[i+offset]){
            printf("%d ",ans[i+offset]);
        }
    }
}

int main(){
    struct node *root=tree();
    printf("Top View: ");
    top(root);
    return 0;
}
