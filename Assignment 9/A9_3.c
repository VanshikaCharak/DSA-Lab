// Problem 3: k smallest 
// A navigation application stores location codes in a BST. Given a target value x and an integer k, the application must retrieve the k stored values closest to x. Write a C program to return the k values having the smallest absolute differences from x. If two values have the same difference, select the smaller value first.
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node *root=NULL;
    int n,k,target;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    int bst[n],dist[n];
    int sm=INT_MAX,lar=INT_MIN;
    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bst[i]);
        if(bst[i]<sm){
            sm=bst[i];
        }
        if(bst[i]>lar){
            lar=bst[i];
        }
    }
    printf("Enter target value: ");
    scanf("%d",&target);
    if(target<sm|| target>lar){
        printf("Target is smaller than the minimum or greater than the maximum element");
        return 0;
    }
    printf("Enter k: ");
    scanf("%d",&k);
    if(k>n){
        printf("Not enough elements");
        return 0;
    }
    for(int i=0;i<n;i++){
        dist[i]=abs(bst[i]-target);
    }
    while(k){
        k--;
        int q=INT_MAX,ind;
        int result;
        for(int i=0;i<n;i++){
            if(dist[i]<q){
                q=dist[i];
                ind=i;
                result=bst[i];
            }
            else if(dist[i]==q){
                if(bst[i]<result){
                    result=bst[i];
                    ind=i;
                }
            }
        }
        bst[ind]=INT_MAX;
        dist[ind]=INT_MAX;
        printf("%d  ",result);
        result=INT_MAX;
    }

    return 0;
}