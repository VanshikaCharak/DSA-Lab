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
};
struct queue{
    struct node *ptr;
    int head;
};
struct node* tree(){
    int data;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct node *root=create(data);
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
    int front=-1,rear=-1;
    struct queue q[20];


}


int main(){
    
    
    return 0;
}