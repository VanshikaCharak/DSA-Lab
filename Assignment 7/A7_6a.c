// Implement Queue using Array. 
#include <stdio.h>
int main(){
    int queue[100],front=-1,rear=-1,choice,x;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            if(rear==99){
                printf("Queue is full");
            }else{
                printf("Enter data: ");
                scanf("%d",&x);
                if(front==-1){
                    front=0;
                }
                queue[++rear]=x;
            }
        }else if(choice==2){
            if(front==-1||front>rear){
                printf("Queue is empty");
            }else{
                printf("Deleted element: %d\n",queue[front]);
                front++;
                if(front>rear){
                    front=-1;
                    rear=-1;
                }
            }
        }else if(choice==3){
            if(front==-1){
                printf("Queue is empty");
            }else{
                printf("Queue: ");
                for(int i=front;i<=rear;i++){
                    printf("%d ",queue[i]);
                }
                printf("\n");
            }
        }else if(choice!=4){
            printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}