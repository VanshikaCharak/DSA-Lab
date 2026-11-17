// Problem 1: HeapSort 
// Write a program that accepts a set of integers, constructs a heap, and sorts the numbers using heap sort.
#include <stdio.h>

void heap(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heap(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for (int i=(n/2)-1;i>=0;i--){
        heap(arr,n,i);
    }
    for (int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heap(arr,i,0);
    }
}

int main(){
    int n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heapSort(arr,n);
    printf("Sorted array: ");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}