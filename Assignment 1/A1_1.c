// Given an array of positive and negative numbers, rearrange it so that positive and negative numbers appear alternately.
#include <stdio.h>

int main(){
    int arr[10]={5,10,-3,2,-1,-6};
    int arrP[10];
    int arrN[10];
    int p=0,n=0;
    for (int i = 0; i < 6; i++)
    {
        if(arr[i]<0){
            arrN[n]=arr[i];
            n++;
        }
        else{
            arrP[p]=arr[i];
            p++;
        }
        
    }
    for(int j=0;j<6;j+=2){
        arr[j]=arrP[j/2];
        arr[j+1]=arrN[j/2];
    }
    for(int k=0;k<6;k++){
        printf("%d   ",arr[k]);
    }
       
    return 0;
}