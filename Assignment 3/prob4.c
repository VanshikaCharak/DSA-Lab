// Problem 4: Equilibrium Index
// A bridge is balanced if the total load on both sides is equal.
// • Given an array representing loads, find all equilibrium indices.
// • An equilibrium index is one where the sum of elements on the left equals the sum of elements on the right.  
#include <stdio.h>

int main(){
    int arr[10]={1,3,5,2,2,3,1,4,2,1};
    int sum=0,left=0,right;
    for(int i=0;i<10;i++){
        sum=sum+arr[i];
    }
    for(int i=0;i<10;i++){
        right=sum-left-arr[i];
        if(left==right){
            printf("%d ",i);
        }
        left=left+arr[i];
    }
    return 0;
}