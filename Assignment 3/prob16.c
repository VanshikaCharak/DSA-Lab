// Problem 16: Array Compression
// A sorted array may contain repeated values.
// • Compress the array by storing each distinct element along with its frequency.
// • Do not use structures or classes. 
#include <stdio.h>

int main(){
    int arr[10]={1,1,2,2,2,3,4,4,5,5};
    int count=1;
    for(int i=1;i<10;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }else{
            printf("%d : %d\n",arr[i-1],count);
            count=1;
        }
    }
    printf("%d : %d\n",arr[9],count);
    return 0;
}