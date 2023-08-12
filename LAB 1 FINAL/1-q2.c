#include<stdio.h>
void print(int arr[],int n )
{
    printf("\n\nThe elements of the array are :\n\n");  
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void prefix_sum(int arr[],int n )
{
    int sum = arr[0];
    for(int i =1 ;i<n ;i++)
    {
        sum = sum +arr[i];
        arr[i]=sum ;
    }
}
int main()
{
    FILE *myFile = fopen("num.txt", "r");
    
    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        return 0;
    }
    
    printf("Enter the size: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;

    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d", &arr[i]);
    }
    printf("\nBefore summing\n");
    print(arr,n);
    prefix_sum(arr,n );
    print(arr,n);
    return 0;
}