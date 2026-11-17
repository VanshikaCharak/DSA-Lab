// Problem 5: Serialize and Deserialize
// A distributed application needs to transmit a binary tree from one server to another. Since pointers cannot be transmitted directly, the tree must be converted into a sequence of values and subsequently reconstructed. 
// Write a C program implementing the following functions: 
// • serialize(root): Converts a binary tree into a string or sequence. 
// • deserialize(data): Reconstructs the original binary tree from that representation.
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
void serialize(struct node* root,char serial[]){
    if(root==NULL){
        return;
    }
    


    
}

int main(){
    int n;
    scanf("%d",&n);
    char serial[n];
    
    
    return 0;
}