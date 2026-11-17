// Problem 2: Threaded Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
    int lthread;
    int rthread;
};

struct node* createNode(int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->lthread=0;
    newNode->rthread=0;
    return newNode;
}

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

void convert(struct node *root,struct node **prev){
    if(root==NULL){
        return;
    }
    convert(root->left,prev);
    if(root->left==NULL){
        root->left=*prev;
        root->lthread=1;
    }
    if(*prev!=NULL && (*prev)->right==NULL){
        (*prev)->right=root;
        (*prev)->rthread=1;
    }
    *prev=root;
    convert(root->right,prev);
}

struct node* leftMost(struct node *root){
    if(root==NULL){
        return NULL;
    }
    while(root->lthread==0 && root->left!=NULL){
        root=root->left;
    }
    return root;
}

void inorder(struct node *root){
    struct node *curr=leftMost(root);
    while(curr!=NULL){
        printf("%d ",curr->val);
        if(curr->rthread==1){
            curr=curr->right;
        }
        else{
            curr=leftMost(curr->right);
        }
    }
}

int main(){
    struct node *root=tree();
    struct node *prev=NULL;
    convert(root,&prev);
    printf("\nInorder traversal: ");
    inorder(root);
    return 0;
}
