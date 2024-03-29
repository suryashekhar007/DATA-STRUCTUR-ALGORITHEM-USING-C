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

void deleteFromBeginning(int arr[], int *size) 
{
    // Shift elements to the left
    for (int i = 0; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

void deleteFromEnd(int arr[], int *size) 
{
    (*size)--;
}

void deleteFromLocation(int arr[], int *size, int location) 
{
    // Shift elements to the left from the given location
    for (int i = location; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

void deleteBeforeAfterElement(int arr[], int *size, int target, char position) 
{
    int location;
    for (int i = 0; i < *size; i++) 
    {
        if (arr[i] == target) {
            location = i;
            break;
        }
    }
    if (position == 'B')
        deleteFromLocation(arr, size, location - 1);
    else if (position == 'A')
        deleteFromLocation(arr, size, location + 1);
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
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    }
    else
    {
    return 0;    
    }
    do {
        printf("\nMenu:\n");
        printf("1. Deletion\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            
            case 1:
                printf("\nDeletion Operations:\n");
                printf("1. Delete from Beginning\n2. Delete from End\n3. Delete from Location\n4. Delete Before/After Element\nEnter your choice: ");
                int deleteChoice;
                scanf("%d", &deleteChoice);
                switch (deleteChoice) 
                {
                    case 1:
                        deleteFromBeginning(arr, &size);
                        break;
                    case 2:
                        deleteFromEnd(arr, &size);
                        break;
                    case 3: {
                        int location;
                        printf("Enter location to delete: ");
                        scanf("%d", &location);
                        deleteFromLocation(arr, &size, location);
                        break;
                    }
                    case 4: {
                        int target;
                        char position;
                        printf("Enter target element: ");
                        scanf("%d", &target);
                        printf("Enter 'B' to delete element before or 'A' to delete element after: ");
                        scanf(" %c", &position);
                        deleteBeforeAfterElement(arr, &size, target, position);
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