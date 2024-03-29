#include<stdio.h>
#include<conio.h>
#define maxsize 10

int cq[maxsize], *rear = NULL, *front = NULL;

int main() {
    int choice;

    do {
        printf("\n---------------CIRCULAR QUEUE---------------\n");
        printf("1 . insert\n");
        printf("2 . delete\n");
        printf("3 . display\n");
        printf("4 . exit\n");
        printf("ENTER YOUR CHOICE  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                {
                    int n;
                    if (((*rear + 1) % maxsize) == front) {
                        printf("queue is overflow");
                    } else {
                        printf("enter the element for insertion: ");
                        scanf("%d", &n);

                        if (rear == NULL && front == NULL) {
                            rear = cq;
                            front = cq;
                        } else {
                            rear = (cq + ((rear - cq + 1) % maxsize));
                        }
                        *rear = n;
                    }
                }
                break;

            case 2: // Delete
                {
                    int n;

                    if (rear == NULL && front == NULL) {
                        printf("queue is empty");
                    } else {
                        n = *front;
                        if (front == rear) {
                            front = NULL;
                            rear = NULL;
                        } else {
                            front = (cq + ((front - cq + 1) % maxsize));
                        }
                        printf("deleted element is %d", n);
                    }
                }
                break;

            case 3: // Display
                {
                    int *i;
                    if (rear == NULL && front == NULL) {
                        printf("queue is empty");
                    } else {
                        printf("element of queue\n");

                        for (i = front; i != rear; i = (cq + ((i - cq + 1) % maxsize))) {
                            printf("%5d", *i);
                        }
                        printf("%5d", *i);
                    }
                }
                break;

            case 4: // Exit
                printf("exit.....................\n");
                break;

            default: // Invalid Choice
                printf("invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
