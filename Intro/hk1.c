#include <stdio.h>
#include <stdlib.h>

// Function to find subarray sums based on the given array and queries
long int* findSum(int numbers[], int n, int queries[][3], int q) {
    long int* arr = (long int*)malloc(q * sizeof(long int));
    if (arr == NULL) {
        // Memory allocation failed
        exit(1);
    }

    for (int i = 0; i < q; ++i) {
        int l = queries[i][0] - 1; // Convert 1-indexed to 0-indexed
        int r = queries[i][1] - 1; // Convert 1-indexed to 0-indexed
        int x = queries[i][2];

        long int sum = 0;
        for (int j = l; j <= r; ++j) {
            sum += numbers[j];
            if (numbers[j] == 0) {
                sum += x; // Add x to the sum for each zero
            }
        }
        arr[i] = sum;
    }

    return arr;
}

int main() {
    // Sample input
    int numbers[] = {20, 30, 0, 10};
    int n = 4;
    int queries[][3] = {{1, 3, 10}};
    int q = 1;

    // Call the findSum function
    long int* result = findSum(numbers, n, queries, q);

    // Print the results
    for (int i = 0; i < q; ++i) {
        printf("Query %d: %ld\n", i + 1, result[i]);
    }

    // Free allocated memory
    free(result);

    return 0;
}
