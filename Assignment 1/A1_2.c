// Write a program to print all subsets of an array whose sum equals a given number. 
#include <stdio.h>

int main(){
    int arr[]={2,5,4,7,8,3,0,-2,1};
    int sum;
    printf("Enter sum required: ");
    scanf("%d",&sum);

    for(int i=0;i<9;i++){
        for(int j=i;j<9;j++){
            if(i!=j && arr[i]+arr[j]==sum){
                printf("{%d  %d}\n",arr[i],arr[j]);
            }
        }
    }
    return 0;
}
