// Implement insertion sort and bubble sort in a single program and measure their execution times for different input sizes. 
#include <stdio.h>

int main(){
    int arr[]={5,2,8,9,1,5,0,3,7,9,4,1,6,5,8,9,1,3,7,5,6};
    int n=sizeof(arr)/4;
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    printf("Final array: \n");
    for(int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        
    }

    return 0;
}