#include<stdio.h>
#define max 10
 int stack[max];
 int top = -1;

void push(){
    int n;
    
    if(top == max-1){
        printf("STACK IS OVER FLOW\n");
    }
    else{
        printf("Enter the number :");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
    

}
void display(){
    
    int i;
    if(top == -1){
        printf("STACK IS EMPTY\n");
    }
    else{
        printf("elements of stack is:\n");
        for(int i = top; i>=0; i--)
            printf("%d\n",stack[i]);
        }
    }

void pop(){
    int n;
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        n = stack[top];
        top --;
    }
}






int main(){
   
    int choice;

    do{

       printf("-------STACK--------\n");
       printf("1.Enter 1 for PUSH:\n");
       printf("1.Enter 2 for display:\n");
       printf("3.Enter 3 for POP:\n");
       printf("4.Enter 4 for EXIT:\n");
       printf("Enter your coice");
       scanf("%d",&choice);

    

        switch(choice){
               case 1:push();
               break;

               case 2:display();
               break;

               case 3:pop();
               break;

               case 4:printf("EXITING..........\n");
               break;

               default:printf("invalid choice\n");

           
            }

    }while (choice !=5);


 return 0;
}