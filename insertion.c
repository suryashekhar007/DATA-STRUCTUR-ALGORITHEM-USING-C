#include <stdio.h>
#include <stdlib.h>

void createDynamicArray(int **arr, int size) 
{
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
}

void traverseArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void insertAtBeginning(int arr[], int *size, int element) 
{
    // Shift elements to the right
    for (int i = *size - 1; i >= 0; i--)
        arr[i + 1] = arr[i];
    arr[0] = element;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int element) 
{
    arr[*size] = element;
    (*size)++;
}

void insertAtLocation(int arr[], int *size, int element, int location)
{
    // Shift elements to the right from the given location
    for (int i = *size - 1; i >= location; i--)
        arr[i + 1] = arr[i];
    arr[location] = element;
    (*size)++;
}

void insertBeforeAfterElement(int arr[], int *size, int element, int target, char position) 
{
    int location;
    for (int i = 0; i < *size; i++) 
    {
        if (arr[i] == target) 
        {
            location = i;
            break;
        }
    }
    if (position == 'B')
        insertAtLocation(arr, size, element, location - 1);
    else if (position == 'A')
        insertAtLocation(arr, size, element, location + 1);
}

int main() {
    int choice, size;
    int *arr = NULL;
    char c;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    createDynamicArray(&arr, size); 

    printf("Do you want to enter array elements(y): "); 
    scanf(" %c",&c);

    if(c=='y' || c=='Y')
    {
    
    for (int i = 0; i < size; i++){
    printf("Enter elements of the array %d: ",i+1);
    scanf("%d", &arr[i]);
    }
    }
    else
    {
    return 0;    
    }
    do {
        printf("\nMenu:\n");
        printf("1. Insertion\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nInsertion Operations:\n");
                printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Location\n4. Insert Before/After Element\nEnter your choice: ");
                int insertChoice;
                scanf("%d", &insertChoice);
                switch (insertChoice) 
                {
                    case 1: {
                        int element;
                        printf("Enter element to insert at beginning: ");
                        scanf("%d", &element);
                        insertAtBeginning(arr, &size, element);
                        break;
                    }
                    case 2: {
                        int element;
                        printf("Enter element to insert at end: ");
                        scanf("%d", &element);
                        insertAtEnd(arr, &size, element);
                        break;
                    }
                    case 3: {
                        int element, location;
                        printf("Enter element to insert: ");
                        scanf("%d", &element);
                        printf("Enter location to insert: ");
                        scanf("%d", &location);
                        insertAtLocation(arr, &size, element, location);
                        break;
                    }
                    case 4: {
                        int element, target;
                        char position;
                        printf("Enter element to insert: ");
                        scanf("%d", &element);
                        printf("Enter target element: ");
                        scanf("%d", &target);
                        printf("Enter 'B' to insert before or 'A' to insert after: ");
                        scanf(" %c", &position);
                        insertBeforeAfterElement(arr, &size, element, target, position);
                        break;
                    }
                    default:
                        printf("Invalid choice!\n");
                }
                break;
           
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (choice != 2) {
            printf("\nArray elements after operation: ");
            traverseArray(arr, size);
            printf("\n");
        }

    } while (choice != 2);
    free(arr); 
    return 0;
}