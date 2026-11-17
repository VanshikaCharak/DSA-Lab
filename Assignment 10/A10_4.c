// Problem 4: Dynamic Product Catalogue (Binary Search Tree)
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
void inorder(struct node *root,int bst[],int *q){
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
    printf("Enter no of elements in bst: ");
    scanf("%d",&n);
    int bst[n];
    printf("Enter bst:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    int ind=0;
    inorder(root,bst,&ind);
    int query[n];
    printf("Enter queries: ");
    int q=0,temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp==-1){
            break;
        }
        if(temp>=0 && temp<n){
            query[i]=temp;
        }
        else{
            printf("Invalid query");
        }
        q++;
    }
    for(int i=0;i<q;i++){
        printf("%d  ",bst[query[i]-1]);
    }
        
    return 0;
}