// Problem 7: Rearranging Positive and Negative Numbers
// A dataset contains both profit and loss values. Rearrange the array so that all negative numbers appear
// before all positive numbers. Preserve the relative order of the elements. Do not use an extra array. 
#include <stdio.h>

int main(){
    int arr[10]={2,-4,7,-1,5,-3,8,-6,9,1};
    int temp;
    for(int i=0;i<10;i++){
        if(arr[i]<0){
            temp=arr[i];
            int j;
            for(j=i;j>0 && arr[j-1]>=0;j--){
                arr[j]=arr[j-1];
            }
            arr[j]=temp;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}