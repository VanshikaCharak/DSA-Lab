// Problem 2: Maximum Profit Difference
// A company records its daily stock prices in an array.
// • Find the maximum possible profit that can be obtained by buying on one day and selling on a later day.
// • If no profit is possible, print 0.
// • Your solution should run in O(n) time. 
#include <stdio.h>

int main(){
    int arr[10]={7,1,5,3,6,4};
    int min=arr[0],profit=0;
    for(int i=1;i<6;i++){
        if(arr[i]-min>profit){
            profit=arr[i]-min;
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("Maximum profit: %d",profit);
    return 0;
}