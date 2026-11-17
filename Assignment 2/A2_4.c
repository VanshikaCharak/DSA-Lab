// Rotate an array to the right by \(k\) positions without using an extra array. \(k\) can be greater than the array length. 
#include <stdio.h>

int rev(int arr[],int a,int b){
    for(int  i=a;i<(a+b)/2;i++){
        int temp=arr[i];
        arr[i]=arr[a+b-i-1];
        arr[a+b-i-1]=temp;
    }
    return 0;  
}

int main(){
    int arr[6]={3,5,1,7,4,2};
    int k;
    printf("Initial array: \n");
    for(int i=0;i<6;i++){
            printf("%d  ",arr[i]);
        
    }
    
    printf("\nEnter no of rotations for array: ");
    scanf("%d",&k);
    if(k>=6)
        k=k-6;

    rev(arr,0,6);// first reversal of whole array

    rev(arr,0,6-k);// second reversal of 
    
    rev(arr,6-k,6);

    printf("Final array: \n");
    for(int i=0;i<6;i++){
            printf("%d  ",arr[i]);
        
    }
    

    return 0;
}