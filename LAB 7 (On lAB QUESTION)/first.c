#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the mean of an array
float calculateMean(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}


float calculateMedian(int arr[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // If the size is odd, return the middle element
    if (size % 2 == 1) {
        return arr[size / 2];
    }
    // If the size is even, return the average of the middle two elements
    return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

// Function to calculate the mode of an array
int calculateMode(int arr[], int size) {
    
    return -1; 
}

// Function to calculate the standard deviation of an array
float calculateStandardDeviation(int arr[], int size, float mean) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / size);
}

// Function to calculate the variance of an array
float calculateVariance(int arr[], int size, float mean) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sum / size;
}

int main() {
    int choice, size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Generate random numbers and fill the array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Change 100 to the desired range
    }
    
    do {
        printf("\nMenu:\n");
        printf("1. Calculate Mean\n");
        printf("2. Calculate Median\n");
        printf("3. Calculate Mode\n");
        printf("4. Calculate Standard Deviation\n");
        printf("5. Calculate Variance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Mean: %.2f\n", calculateMean(arr, size));
                break;
            case 2:
                printf("Median: %.2f\n", calculateMedian(arr, size));
                break;
            case 3:
                printf("Mode: %d\n", calculateMode(arr, size));
                break;
            case 4:
                printf("Standard Deviation: %.2f\n", calculateStandardDeviation(arr, size, calculateMean(arr, size)));
                break;
            case 5:
                printf("Variance: %.2f\n", calculateVariance(arr, size, calculateMean(arr, size)));
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}