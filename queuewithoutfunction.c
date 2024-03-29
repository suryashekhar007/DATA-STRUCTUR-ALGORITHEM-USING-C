#include<stdio.h>
#include<conio.h>
#define maxsize 10
int queue[maxsize];
int rear = -1;
int front = 0;

int main(){
    int choice;

    do{
        printf("-----------------QUEUE----------------\n");
        printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("-----------------------------------------\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Insert
                {
                    int n;
                    if(rear == maxsize-1){
                        printf("Queue is overflow\n");
                    }
                    else{
                        printf("Enter the element: ");
                        scanf("%d", &n);
                        rear++;
                        queue[rear] = n;
                    }
                }
                break;

            case 2: // Delete
                {
                    int n;
                    if(front > rear){
                        printf("Queue is empty\n");
                    }
                    else{
                        n = queue[front];
                        printf("Deleted element is %d\n", n);
                        front++;
                    }
                }
                break;

            case 3: // Display
                {
                    if(front > rear){
                        printf("Queue is empty\n");
                    }
                    else{
                        printf("Queue elements are:\n");
                        for(int i = rear; i >= front; i--){
                            printf("%d\n", queue[i]);
                        }
                    }
                }
                break;

            case 4: // Exit
                printf("Exit....................\n");
                break;

            default: // Invalid Choice
                printf("Invalid choice\n");
        }
    }while(choice != 4);

    return 0;
}
