#include<stdio.h>
void print(int arr[],int n )
{
    printf("The elements of the array are :");  
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void rotate(int arr[],int n ,int a)
{
    int rotated=arr[a-1];
    for(int i = a-1; i>=0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=rotated;
}
int main()
{
    FILE *myFile;
    myFile = fopen("hello.txt", "r");
    printf("Enter the size: ");
    int n ;
    scanf("%d",&n);
    int arr[n];
    int i;

    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d", &arr[i]);
    }
    printf("\nBefore rotating\n");

    print(arr,n);
    printf("\n Enter the position a :");
    int a;
    scanf("%d",&a);
    rotate(arr,n,a);
    print(arr,n);
    return 0;
}