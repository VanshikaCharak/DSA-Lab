// Implement insertion sort and bubble sort in a single program and measure their execution times for different input sizes. 
#include <stdio.h>

int main(){

    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    int arr[n];
    for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Final array: \n");
    for(int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        
    }

    return 0;
}