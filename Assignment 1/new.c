#include<stdio.h>
int main(){
    int s=0;
    int k=1;
    int t[6];
    int a[6]={5,10,-3,2,-1,-6};
    for(int i=0;i<6;i++){
        if(a[i]>0){
            t[s]=a[i];
            s=s+2;

        }
        if(a[i]<0){
            t[k]=a[i];
            k=k+2;
        }
    }
    for(int i=0;i<6;i++){
        printf("%d\n",t[i]);
    }

}