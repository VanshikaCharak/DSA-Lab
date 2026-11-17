#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};
struct node *createNode(int val){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insert(struct node *root, int value){
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->val){
        root->left = insert(root->left, value);
    }
    else if (value > root->val){
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(struct node *root, int bst[], int *q){
    if (root == NULL)
        return;
    inorder(root->left, bst, q);
    bst[*q] = root->val;
    (*q)++;
    inorder(root->right, bst, q);
}
struct node *BUILD(int arr[],int n){
    struct node *root = NULL;
    for (int i=0;i <n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
int NEXT(int bst[],int n,int x){
    for(int i=0;i<n;i++){
        if(bst[i]==x && i+1<n){
            return bst[i+1];
        }
    }
    printf("NULL");
    return -1;
}
int PREV(int bst[],int n,int x){
    for(int i=0;i<n;i++){
        if(bst[i]==x && i-1>=0){
            return bst[i-1];
        }
    }
    printf("NULL");
    return -1;

}
int RANGE(int bst[],int n,int l,int r){
    int start=-1,end=-1;
    if(l>r){
        printf("NULL");
        return -1;
    }
    for(int i=0;i<n;i++){
        if(bst[i]>=l && start==-1){
            start=i;
        }
        if(bst[i]<=r){
            end=i;
        }
        
    }
    if(start>end || start==-1 || end==-1){
        printf("NULL");
        return -1;
    }
    for(int i=start;i<=end;i++){
        printf("%d  ",bst[i]);
    }
    return 0;
}
int KTH(int bst[],int n,int k){
    if(k>0 && k<=n){
        return bst[k-1];
    }
    printf("NULL");
    return -1;
}

int main()
{
    struct node *root=NULL;
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("BUILD: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    root=BUILD(arr,n);
    int bst[n];
    int ind=0;
    inorder(root,bst,&ind);

    int x,l,r,k;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter l and r: ");
    scanf("%d %d",&l,&r);
    printf("Enter k: ");
    scanf("%d",&k);
    printf("NEXT %d: %d",x,NEXT(bst,ind,x));
    printf("\nPREV %d: %d",x,PREV(bst,ind,x));
    printf("\nRANGE %d %d: ",l,r);
    RANGE(bst,ind,l,r);
    printf("\nKTH %d: %d",k,KTH(bst,ind,k));

    return 0;
}
// 40 20 60 10 30 50 70 