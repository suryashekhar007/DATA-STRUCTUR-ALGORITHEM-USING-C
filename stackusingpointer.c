#include<stdio.h>
#include<stdlib.h>

#define max 10

int stack[max];
int *top = NULL;

void push() {
    int n;
    if (top == &stack[max - 1]) {
        printf("STACK IS OVER FLOW\n");
    } else {
        printf("Enter the number: ");
        scanf("%d", &n);
        if (top == NULL) {
            top = &stack[0];
        } else {
            top++;
        }
        *top = n;
    }
}

void display() {
    if (top == NULL) {
        printf("STACK IS EMPTY\n");
    } else {
        printf("elements of stack are:\n");
        int *ptr = top;
        while (ptr >= &stack[0]) {
            printf("%d\n", *ptr);
            ptr--;
        }
    }
}

void pop() {
    int n;
    if (top == NULL) {
        printf("stack is empty\n");
    } else {
        n = *top;
        top--;
    }
}

int main() {
    int choice;
    do {
        printf("-------STACK--------\n");
        printf("1. Enter 1 for PUSH:\n");
        printf("2. Enter 2 for display:\n");
        printf("3. Enter 3 for POP:\n");
        printf("4. Enter 4 for EXIT:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:
                printf("EXITING..........\n");
                break;
            default:
                printf("invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
