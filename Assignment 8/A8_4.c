// Write a program for implementation of merge sort on an array.  
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
struct node* insert(struct node *root,int value) {
    if(root==NULL){
        return createNode(value);
    }
    if(value<root->val){
        root->left=insert(root->left,value);
    }else if(value>root->val){
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(struct node *root,int bst[20],int *q){
    if(root==NULL)
        return;
    inorder(root->left,bst,q);
    bst[*q]=root->val;
    (*q)++;
    inorder(root->right,bst,q);
    
}

int main(){
    struct node *root=NULL;
    int n,val;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    int bst[n],arr[n];
    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
        arr[i]=val;
    }
    int ind=0;
    inorder(root,bst,&ind);
    printf("Sorted array using BST:\n");
    for(int i=0;i<n;i++){
        printf("%d ",bst[i]);
    }    
    return 0;
}