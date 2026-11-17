// Problem 4: Maximum SubTree 
// A financial analytics system represents a hierarchical portfolio using a binary tree. Each node contains the net value of a portfolio component. Some subtrees satisfy the BST property, while others do not. 
// Write a C program to find the maximum sum of node values among all subtrees that are valid BSTs. 
// A subtree is a valid BST if every value in its left subtree is strictly smaller than its root and every value in its right subtree is strictly greater than its root.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct info{
    int min;
    int max;
    int sum;
    int isBST;
};

int maxSum=0;
struct info findMax(struct node *root){
    struct info curr;
    if(root==NULL){
        curr.min=INT_MAX;
        curr.max=INT_MIN;
        curr.sum=0;
        curr.isBST=1;
        return curr;
    }
    struct info left=findMax(root->left);
    struct info right=findMax(root->right);
    if(left.isBST && right.isBST &&
       left.max<root->val && root->val<right.min){
        curr.isBST=1;
        curr.sum=left.sum+right.sum+root->val;
        if(root->val<left.min){
            curr.min=root->val;
        }
        else{
            curr.min=left.min;
        }

        if(root->val>right.max){
            curr.max=root->val;
        }
        else{
            curr.max=right.max;
        }
        if(curr.sum>maxSum){
            maxSum=curr.sum;
        }
    }
    else{
        curr.isBST=0;
        curr.sum=0;
        curr.min=INT_MIN;
        curr.max=INT_MAX;
    }
    return curr;
}

int main(){
    struct node *root=tree();
    maxSum=0;
    findMax(root);
    printf("Maximum sum of BST subtree: %d",maxSum);
    return 0;
}