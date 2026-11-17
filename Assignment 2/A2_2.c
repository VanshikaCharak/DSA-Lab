// Find the second-largest and second-smallest numbers in an array without sorting. The array may contain duplicate elements. 
#include <stdio.h>

int main(){
    int arr[10]={3,5,6,1,8,12,0,-5,3,9};
    int l1,l2,s1,s2;
    if(arr[0]>arr[1]){
        l1=arr[0],l2=arr[1];
    }else{
        l1=arr[1],l2=arr[0];
    }
    if(arr[0]<arr[1]){
        s1=arr[0],s2=arr[1];
    }else{
        s1=arr[1],s2=arr[0];
    }

    for(int i=2;i<10;i++){
        // Second largest 
        if(arr[i]>l1 && arr[i]>l2){
            l2=l1;
            l1=arr[i];
        }
        else if(arr[i]>!l1 && arr[i]>l2)
            l2=arr[i];
        // Second smallest 
        if(arr[i]<s1 && arr[i]<s2){
            s2=s1;
            s1=arr[i];
        }
        else if(arr[i]<!s1 && arr[i]<s2)
            s2=arr[i];

            
            
        }
    printf("Second Largest: %d\n",l2);
    printf("Second Smallest: %d",s2);
    return 0;
}