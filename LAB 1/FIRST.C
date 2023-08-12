#include <stdio.h>
#include <stdlib.h>

void findSecondSmallestAndSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array size must be at least 2.\n");
        return;
    }

    int smallest = arr[0], secondSmallest = arr[0];
    int largest = arr[0], secondLargest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

            secondLargest = largest;
        if (arr[i] > largest) { 
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1) {
        printf("Failed to read array size from the file.\n");
        fclose(file);
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Failed to read element at index %d from the file.\n", i);
            free(arr);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    findSecondSmallestAndSecondLargest(arr, n);

    free(arr);

    return 0;
}