// The Bus Stop Queue Conundrum
// Given the array stress and the integer threshold K, find the maximum number of consecutive passengers the
// conductor can board in a single group without starting an argument. 
#include <stdio.h>

int main(){
    int arr[100],n,k,max,min,len,maxlen=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter K: ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        max=arr[i];
        min=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]>max){
                max=arr[j];
            }
            if(arr[j]<min){
                min=arr[j];
            }
            if(max-min<=k){
                len=j-i+1;
                if(len>maxlen){
                    maxlen=len;
                }
            }else{
                break;
            }
        }
    }
    printf("Maximum length: %d",maxlen);
    return 0;
}