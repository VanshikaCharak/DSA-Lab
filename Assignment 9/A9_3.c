// Problem 3: k smallest 
// A navigation application stores location codes in a BST. Given a target value x and an integer k, the application must retrieve the k stored values closest to x. Write a C program to return the k values having the smallest absolute differences from x. If two values have the same difference, select the smaller value first.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n,k,target;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    int bst[n],dist[n];
    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bst[i]);
    }
    printf("Enter target value: ");
    scanf("%d",&target);
    printf("Enter k: ");
    scanf("%d",&k);
    if(k>n || k<=0){
        printf("Invalid value of k");
        return 0;
    }
    for(int i=0;i<n;i++){
        dist[i]=abs(bst[i]-target);
    }
    while(k){
        k--;
        int q=INT_MAX,ind=-1;
        int result;
        for(int i=0;i<n;i++){
            if(dist[i]<q){
                q=dist[i];
                ind=i;
            }
            else if(dist[i]==q && ind!=-1){
                if(bst[i]<bst[ind]){
                    ind=i;
                }
            }
        }
        result=bst[ind];
        printf("%d ",result);
        bst[ind]=INT_MAX;
        dist[ind]=INT_MAX;
    }
    return 0;
}
