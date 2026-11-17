// Problem 2: Malfunctioned BST 
// A university maintains student records in a Binary Search Tree (BST), where each node stores a unique student ID. Due to a software malfunction, the values of exactly two nodes have been swapped. The tree structure remains unchanged. 
// Write a C program to recover the original BST by correcting the two swapped values without modifying the tree structure.
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

struct node* insert(struct node *root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

struct node *first=NULL,*middle=NULL,*last=NULL,*prev=NULL;

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(prev!=NULL && prev->val>root->val){
        if(first==NULL){
            first=prev;
            middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
}

void recover(struct node *root){
    inorder(root);
    if(first!=NULL && last!=NULL){
        int temp=first->val;
        first->val=last->val;
        last->val=temp;
    }
    else if(first!=NULL && middle!=NULL){
        int temp=first->val;
        first->val=middle->val;
        middle->val=temp;
    }
}

void display(struct node *root){
    if(root==NULL){
        return;
    }
    display(root->left);
    printf("%d ",root->val);
    display(root->right);
}

int main(){
    struct node *root=NULL;
    int n,val;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("Inorder before recovery: ");
    display(root);
    recover(root);
    printf("\nInorder after recovery: ");
    display(root);
    return 0;
}
