#include <stdio.h>
#include <stdlib.h>

void print(int arr[],int n )
{
    printf("The elements of the array are :");  
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++) 
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }
}
int main()
{
    FILE *myFile;
    myFile = fopen("C:/Users/Yatharth Jain/Desktop/Code/DAA/Array/Lab-01/num.txt", "r");
    printf("Enter the size: ");
    int n ;
    scanf("%d",&n);
    int arr[n];
    int i;

    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d", &arr[i]);
    }
    print(arr,n);
    bubble_sort(arr,n);
    printf("\n21051918\nYatharth Jain");
    printf("\nThe second largest = %d\nsecond smallest element => %d ",arr[n-2],arr[1]);
    return 0;
}