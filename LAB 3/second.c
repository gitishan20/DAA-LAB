#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n)
{
    int temp, j, count = 0;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            count++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Number of comparisons made: %d\n", count);
}                                   

int main(){
    printf("MAIN MENU (INSERTION SORT)\n");
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
        fp2 = fopen("outInsAsce.dat", "w");
        int n=300;        
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &a[i]);
        }
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 2:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inDesc.dat", "r");
        fp2 = fopen("outInsDesc.dat", "w");
        int n=300;    
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &a[i]);
        }


        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 3:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inRand.dat", "r");
        fp2 = fopen("outInsRand.dat", "w");
        int n=300;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &a[i]);
        }
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 4:
    {
        exit(0);
        break;
    }
    default:
    {
        printf("Invalid choice\n");
        break;
    }
    }   
    return 0;
}