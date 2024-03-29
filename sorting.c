#include <stdio.h>

void Sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter the %d element : ", i+1);
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    Sort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
