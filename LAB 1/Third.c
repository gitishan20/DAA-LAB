
#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int duplicates = 0;
    int maxRepeatElement = arr[0];
    int maxRepeatCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            duplicates += count - 1;
            if (count > maxRepeatCount) {
                maxRepeatElement = arr[i];
                maxRepeatCount = count;
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", duplicates);
    printf("Most repeating element: %d (repeated %d times)\n", maxRepeatElement, maxRepeatCount);
}

int main() {
    int n;
    printf("2105884 Gitishan\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read integers from the disk file into the array
    FILE *file = fopen("third.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Content of the file (third.txt):\n");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(file);

    findDuplicates(arr, n);

    return 0;
}