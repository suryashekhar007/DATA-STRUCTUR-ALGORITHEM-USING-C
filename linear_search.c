#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Key found, return the index
        }
    }
    return -1; // Key not found
}

int main() {
    int n;
    printf("Enter the size of element:");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
