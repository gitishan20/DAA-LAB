
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right, long long int *comparisonCount) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        (*comparisonCount)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];6566546
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, long long int *comparisonCount) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        mergeSort(arr, left, mid, comparisonCount);
        mergeSort(arr, mid + 1, right, comparisonCount);

        // Merge the sorted halves
        merge(arr, left, mid, right, comparisonCount);
    }
}

// Function to generate random data
void generateRandomData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generating random numbers between 0 and 999
    }
}

// Function to display array elements
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;
    long long int comparisonCount;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 4) {
        printf("Exiting the program.\n");
        return 0;
    }

    printf("Enter the number of elements (between 300 and 500): ");
    scanf("%d", &n);

    if (n < 300 || n > 500) {
        printf("Invalid input! Number of elements must be between 300 and 500.\n");
        return 1;
    }

    int arr[n];

    // Read data from the appropriate file or generate random data
    switch (choice) {
        case 1: // Ascending Data
            for (int i = 0; i < n; i++) {
                arr[i] = i + 10; // Generate ascending data
            }
            break;

        case 2: // Descending Data
            for (int i = 0; i < n; i++) {
                arr[i] = 90 - i; // Generate descending data
            }
            break;

        case 3: // Random Data
            srand(time(NULL)); // Seed for random number generation
            generateRandomData(arr, n);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display original data (optional)
    printf("Original Data: ");
    displayArray(arr, n);

    // Merge Sort and measure execution time
    clock_t start_time = clock();
    comparisonCount = 0; // Initialize comparison count
    mergeSort(arr, 0, n - 1, &comparisonCount);
    clock_t end_time = clock();

    // Calculate execution time in seconds
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Display sorted data
    printf("Sorted Data: ");
    displayArray(arr, n);

    // Display the number of comparisons and execution time
    printf("Number of Comparisons: %lld\n", comparisonCount);
    printf("Execution Time: %f seconds\n", execution_time);

    // Write the sorted data to an output file
    FILE *outputFile;
    switch (choice) {
        case 1:
            outputFile = fopen("outMergeAsce.dat", "w");
            break;
        case 2:
            outputFile = fopen("outMergeDesc.dat", "w");
            break;
        case 3:
            outputFile = fopen("outMergeRand.dat", "w");
            break;
    }

    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);

    return 0;
}