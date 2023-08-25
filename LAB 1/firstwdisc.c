#include <stdio.h>

void find_second_smallest_largest(int arr[], int n, int *second_smallest, int *second_largest) {
    if (n < 2) {
        *second_smallest = *second_largest = -1; // Indicates not enough elements
        return;
    }

    // Sort the array (you can use any sorting algorithm)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    *second_smallest = arr[1];
    *second_largest = arr[n - 2];
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int integers[1000]; // Assuming an array of maximum 1000 integers

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &integers[i]);
    }

    int second_smallest, second_largest;
    find_second_smallest_largest(integers, n, &second_smallest, &second_largest);

    if (second_smallest == -1 || second_largest == -1) {
        printf("Array has less than 2 unique elements.\n");
    } else {
        printf("Second Smallest: %d\n", second_smallest);
        printf("Second Largest: %d\n", second_largest);
    }

    return 0;
}
