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

int serial[1000],index=0;

void serialize(struct node *root){
    if(root==NULL){
        serial[index++]=-1;
        return;
    }
    serial[index++]=root->val;
    serialize(root->left);
    serialize(root->right);
}

struct node* deserialize(){
    int val=serial[index++];
    if(val==-1){
        return NULL;
    }
    struct node *root=createNode(val);
    root->left=deserialize();
    root->right=deserialize();
    return root;
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
    struct node *root=tree();
    index=0;
    serialize(root);
    printf("\nSerialized sequence: ");
    for(int i=0;i<index;i++){
        printf("%d ",serial[i]);
    }
    int size=index;
    index=0;
    struct node *newRoot=deserialize();
    printf("\nInorder after deserialization: ");
    display(newRoot);
    return 0;
}