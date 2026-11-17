// Problem 3: Town Judge
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node* createNode(int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->parent=NULL;
    return newNode;
}

struct node* tree(int arr[],int n){
    if(n==0 || arr[0]==-1){
        return NULL;
    }
    struct node *root=createNode(arr[0]);
    struct node *q[100000];
    int front=0,rear=0,i=1;
    q[rear++]=root;
    while(i<n && front<rear){
        struct node *curr=q[front++];
        if(i<n && arr[i]!=-1){
            curr->left=createNode(arr[i]);
            curr->left->parent=curr;
            q[rear++]=curr->left;
        }
        i++;
        if(i<n && arr[i]!=-1){
            curr->right=createNode(arr[i]);
            curr->right->parent=curr;
            q[rear++]=curr->right;
        }
        i++;
    }
    return root;
}

struct node* search(struct node *root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->val==target){
        return root;
    }
    struct node *left=search(root->left,target);
    if(left!=NULL){
        return left;
    }
    return search(root->right,target);
}

void distanceK(struct node *root,int target,int k){
    struct node *start=search(root,target);
    if(start==NULL){
        return;
    }
    struct node *q[100000];
    struct node *visited[100000];
    int front=0,rear=0,count=0;
    q[rear++]=start;
    visited[count++]=start;
    int dist=0;
    while(front<rear){
        if(dist==k){
            while(front<rear){
                printf("%d ",q[front++]->val);
            }
            return;
        }
        int size=rear-front;
        for(int i=0;i<size;i++){
            struct node *curr=q[front++];
            struct node *next[3]={
                curr->left,
                curr->right,
                curr->parent
            };
            for(int j=0;j<3;j++){
                if(next[j]==NULL){
                    continue;
                }
                int found=0;
                for(int x=0;x<count;x++){
                    if(visited[x]==next[j]){
                        found=1;
                        break;
                    }
                }
                if(!found){
                    visited[count++]=next[j];
                    q[rear++]=next[j];
                }
            }
        }
        dist++;
    }
}

int main(){
    int n,target,k;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter level order elements (-1 for NULL):\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter target value: ");
    scanf("%d",&target);
    printf("Enter K: ");
    scanf("%d",&k);
    struct node *root=tree(arr,n);
    printf("Nodes at distance %d: ",k);
    distanceK(root,target,k);
    return 0;
}