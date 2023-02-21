#include<bits/stdc++.h>
using namespace std;

void combination(int n,int arr[], int pos, int remain, int curr[], int k)
{
    //printf("\n pos %d  rem %d  curr %d     ",pos,remain,curr[k-remain]);
    if(pos>n)
        return;
    if(remain==0)
    {
        for(int i=0; i<k; i++)
            printf("%d ", curr[i]);
        printf("\n");
        return;
    }

    curr[k-remain]=arr[pos];
    combination(n,arr,pos+1,remain-1,curr,k);//Taking number
    combination(n,arr,pos+1,remain,curr,k);//Not taking number

}


// Driver code
int main()
{
    int arr[] = {1, 2, 3,4,5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int curr[r];
    combination(n,arr,0,r,curr,r);
}
