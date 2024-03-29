#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void traverse(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
    
    }
    printf("Linked List: ");
    while
     (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int newData) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

void insertAtEnd(struct Node* head, int newData) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    while (head->next != NULL) 
    {
        head = head->next;
    }
    head->next = newNode;
}

void insertAtLocation(struct Node* head, int location, int newData) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;
    for (int i = 1; i < location; i++) 
    {
        head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;
}

struct Node* deleteAtBeginning(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteAtEnd(struct Node* head) 
{
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
        free(temp);
    } else {
        // Only one node in the list
        free(head);
        head = NULL;
    }
}

void deleteAtLocation(struct Node* head, int location) 
{
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < location; i++) 
    {
        if (temp == NULL) 
        {
            printf("Invalid location.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        printf("Invalid location.\n");
        return;
    }
    if (prev != NULL) 
    {
        prev->next = temp->next;
        free(temp);
    } else {
        // Deleting the first node
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, location;
    char c;
    int i=1,n;
    printf("Do you want to enter data(y): "); 
    scanf(" %c",&c);
    if(c=='y' || c=='Y')
    {
        printf("enter the no. of nodes needed: ");
        scanf("%d",&n);
        while(i<=n)
        {
        printf("Enter data for the node: ");
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
        i++;
        }
    while (1) 
    {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Location\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                traverse(head);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                if (head == NULL) 
                {
                    head = insertAtBeginning(head, data);
                } else 
                {
                    insertAtEnd(head, data);
                }
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter location to insert: ");
                scanf("%d", &location);
                insertAtLocation(head, location, data);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                deleteAtEnd(head);
                break;
            case 7:
                printf("Enter location to delete: ");
                scanf("%d", &location);
                deleteAtLocation(head, location);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    }
    else
    {
        return 0;
    }
    return 0;
}