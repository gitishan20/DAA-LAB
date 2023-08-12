#include<stdio.h>
void print(int arr[],int n )
{
    printf("\n\nThe elements of the array are :\n\n");  
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int count(int arr[],int n,int *index)
{
    int ans[n];
    int max_index=0;
    int curr_count=0,last_count=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        ans[i]=arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(ans[i]!=-1){
            curr_count=0;
        for(int j=i+1;j<n ;j++)
        {
            if(ans[i]==ans[j])
            {
                if(curr_count==0)
                {
                count++;
                }
                curr_count++;
                ans[j]=-1;
            }
        }
        if(curr_count>last_count)
        {
            max_index=i;
            last_count=curr_count;
        }
        }
    }
    if(count==0)
    {
        max_index=-1;
    }
    *index=max_index;
    return count;
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
    printf("\nBefore action");
    print(arr,n);
    int index=0;
    int num=count(arr,n,&index);
    printf("\nThe index is %d and value is %d ",index,arr[index]);
    printf("\nThe count of duplicates is :%d",num);
    return 0;
}