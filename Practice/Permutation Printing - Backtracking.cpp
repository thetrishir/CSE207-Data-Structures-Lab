#include <stdio.h>

void display(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
        printf("%d",arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permut(int *arr, int start, int end)
{
    if(start==end)
        display(arr, end+1);
        return;
    int i;
    for(i=start; i<=end; i++)
    {
        swap((arr+i), (arr+start));
        permut(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int i;
    int arr[size];
    printf("Enter the values:\n");
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    permut(arr, 0, size-1);
    return 0;
}
