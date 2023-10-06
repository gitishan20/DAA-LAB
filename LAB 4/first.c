#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void merge(int arr[], int l, int m, int r)
{
    int temp[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
        count++;
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inAsce.dat", "r");
        fp2 = fopen("outMergeAsce.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }

    case 2:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inDesc.dat", "r");
        fp2 = fopen("outMergeDesc.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }

    case 3:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inRand.dat", "r");
        fp2 = fopen("outMergeRand.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 4:
    {
        printf("Ending...\n");
        exit(0);
    }

    }
}