// Write a program to insert or delete an element from an array. 
#include <stdio.h>

int main(){
    int arr[]={3,1,6,8,5,0,4};
    printf("Enter i for insertion and d for deleting an array element: ");
    char l;
    scanf("%c",&l);
    int n;
    printf("Enter element: ");
    scanf("%d",&n);
    if(l=='i'){
        int i;
        printf("Enter index of insertion: ");
        scanf("%d",&i);
        for(int j=6;j>=i;j--){
            arr[j+1]=arr[j];    
        }
        arr[i]=n;
        printf("Final array:\n");
        for(int i=0;i<8;i++){
            printf("%d  ",arr[i]);
        }
    }
    else if(l=='d'){
        int k;
        for(int i=0;i<7;i++){
            if(arr[i]==n){
                k=i;
            }
        }
        for(int i=k;i<7;i++){
            arr[i]=arr[i+1];
        }
        printf("Final array:\n");
        for(int i=0;i<6;i++){
            printf("%d  ",arr[i]);
        }
    }

    return 0;
}