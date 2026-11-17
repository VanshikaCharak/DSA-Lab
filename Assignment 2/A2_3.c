// Accept an \(m \times n\) matrix and convert it into sparse matrix representation using row-column-value format. 
#include <stdio.h>

int main(){
    int m,n;
    printf("Enter size of array in m x n format: ");
    scanf("%d x %d",&m,&n);
    int arr[m][n];
    int x;
    printf("Enter elements of matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int row[10],col[10],val[10],ind=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                row[ind]=i;
                col[ind]=j;
                val[ind]=arr[i][j];
                ind++;
            }
        }
    }
    printf("The Row Column Value representation is:\n");
    for(int k=0;k<ind;k++){
        printf("%d   %d   %d\n",row[k],col[k],val[k]);
    }


    return 0;
}