//Write a program to implement Binary Search to give the position of leftmost appearance
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key, int *comparisons) {
  while (low <= high) {
    int mid = (low + high) / 2;
    (*comparisons)++;
    
    if (arr[mid] == key) {
      int i;
      for (i = mid - 1; i >= low && arr[i] == key; i--) {
        (*comparisons)++;
      }
      return i + 1;
    } else if (arr[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1; 
}

int main() {
  int n, arr[100], key, i, comparisons = 0;

  printf("2105884 Gitishan\n");
  printf("Enter size of array: ");
  scanf("%d", &n);

  printf("Enter elements of the array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the key to be searched: ");
  scanf("%d", &key);

  int index = binarySearch(arr, 0, n - 1, key, &comparisons);

  if (index == -1) {
    printf("Key not found in the array.");
  } else {
    printf("%d found at index position %d\n", key, index);
  }

  printf("Number of comparisons: %d\n", comparisons);

  return 0;
}