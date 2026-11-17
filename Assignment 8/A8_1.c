// Write a program to check if a binary tree is symmetric or not i.e. it is a mirror image.  
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
int isMirror(struct node *left,struct node *right){
    if(left==NULL &&right==NULL)
        return 1;
    if(left==NULL||right==NULL)
        return 0;
    if(left->val!=right->val)
        return 0;
    return isMirror(left->left,right->right) && isMirror(left->right,right->left);
}

int main(){
    struct node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(2);
    root->left->left=createNode(3);
    root->left->right=createNode(4);
    root->right->left=createNode(4);
    root->right->right=createNode(3);
    if (isMirror(root->left,root->right))
        printf("The tree is symmetric");
    else
        printf("The tree is not symmetric");
            
    return 0;
}