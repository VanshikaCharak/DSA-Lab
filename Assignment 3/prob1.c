// Problem 1: nth Largest Element
// An e-commerce website records the daily sales of a product in an array.
// • Write a program to find the nth largest distinct element in the array.
// • Do not sort the array.
// • Traverse the array only once 
#include <stdio.h>

int main(){
    int arr[10]={12,5,8,12,3,9,5,15,7,10};
    int lar[10];
    int n,count=0,found;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        found=0;
        for(int j=0;j<count;j++){
            if(lar[j]==arr[i]){
                found=1;
                break;
            }
        }
        if(found==0){
            int pos=count;
            for(int j=0;j<count;j++){
                if(arr[i]>lar[j]){
                    pos=j;
                    break;
                }
            }
            for(int j=count;j>pos;j--){
                lar[j]=lar[j-1];
            }
            lar[pos]=arr[i];
            count++;
        }
    }
    if(n>0 && n<=count){
        printf("%d",lar[n-1]);
    }else{
        printf("Invalid n");
    }
    return 0;
}