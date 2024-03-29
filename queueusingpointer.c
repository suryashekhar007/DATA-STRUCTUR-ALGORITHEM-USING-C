#include<stdio.h>
#include<stdlib.h>

#define maxsize 5

int queue[maxsize];
int *rear = NULL;
int *front = NULL;

void insert() {
    int n;
    if (rear == &queue[maxsize - 1]) {
        printf("queue is overflow\n");
    } else {
        printf("enter the element: ");
        scanf("%d", &n);
        if (rear == NULL && front == NULL) {
            rear = front = &queue[0];
        } else {
            rear++;
        }
        *rear = n;
    }
}

void delete() {
    int n;
    if (front == NULL) {
        printf("QUEUE IS EMPTY\n");
    } else {
        n = *front;
        printf("deleted element is %d\n", n);
        if (front == rear) {
            front = rear = NULL;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("queue elements are:\n");
        int *ptr = rear;
        while (ptr >= front) {
            printf("%d\n", *ptr);
            ptr--;
        }
    }
}

int main() {
    int choice;
    do {
        printf("-----------------QUEUE----------------\n");
        printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("---------------------------------------\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exit....................\n");
                break;
            default:
                printf("invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
