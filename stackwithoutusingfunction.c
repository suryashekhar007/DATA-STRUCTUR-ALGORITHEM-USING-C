#include<stdio.h>
#define max 10
int stack[max];
int top = -1;

int main(){
    int choice;

    do {
        printf("-------STACK--------\n");
        printf("1. Enter 1 for PUSH:\n");
        printf("2. Enter 2 for display:\n");
        printf("3. Enter 3 for POP:\n");
        printf("4. Enter 4 for EXIT:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int n, i;
        switch (choice) {
            case 1: // Push
                if (top == max - 1) {
                    printf("STACK IS OVER FLOW\n");
                } else {
                    printf("Enter the number: ");
                    scanf("%d", &n);
                    top++;
                    stack[top] = n;
                }
                break;

            case 2: // Display
                if (top == -1) {
                    printf("STACK IS EMPTY\n");
                } else {
                    printf("Elements of stack are:\n");
                    for (i = top; i >= 0; i--) {
                        printf("%d\n", stack[i]);
                    }
                }
                break;

            case 3: // Pop
                if (top == -1) {
                    printf("STACK IS EMPTY\n");
                } else {
                    printf("Popped element is: %d\n", stack[top]);
                    top--;
                }
                break;

            case 4: // Exit
                printf("EXITING..........\n");
                break;

            default: // Invalid Choice
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
