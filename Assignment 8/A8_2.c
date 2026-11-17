//  Write a program to check the minimum depth of a binary tree.  
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
int depth(struct node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL &&root->right==NULL)
        return 1;
    if(root->left==NULL)
        return 1+depth(root->right);
    if(root->right==NULL)
        return 1+depth(root->left);
    int leftDepth=depth(root->left);
    int rightDepth=depth(root->right);
    if(leftDepth<rightDepth)
        return 1+leftDepth;
    else
        return 1+rightDepth;
}

int main(){
    struct node *root=createNode(8);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    printf("Minimum depth: %d",depth(root));
    
    return 0;
}