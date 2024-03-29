#include<stdio.h>
#include<conio.h>
#define maxsize 5
int queue[maxsize];
int rear = -1;
int front = 0;

void insert(){
    int n;
    if(rear == maxsize-1){
        printf("queue is overflow");
    }
    else{
        printf("enter the element");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}
void delete(){
    int n;
    if(front>rear){
        printf("QUEUE IS EMPTY");

    }
    else{
        n=queue[front];
        printf("deleted element is %d",n);
        front++;
    }
}
void display(){
    if(front>rear){
        printf("queue is empty");

    }
    else{
        printf("queue elements are  \n");
        for(int i = rear; i>=front; i--){
            printf("%d  \n",queue[i]);
        }
    }
}


int main(){

    
    
        int choice;
do{
        printf("-----------------QUEUE----------------\n");
        printf("1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n");
        printf("-----------------------------------------\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&choice);




        switch(choice){
    
               case 1: insert();
               break;

               case 2: delete();
               break;

               case 3: display();
               break;

               case 4:printf("exit....................\n");
               break;

               default:printf("invalid choice\n");
            }
    }while(choice!=5);

     



}
