#include <bits/stdc++.h>
using namespace std;

void bin(int n, int arr[], int pos, int k)
{
    int c= 0;
    if(pos==n)
    {
        for(int i=0; i<n; i++)
            if(arr[i]==1)
                c++;

        if(c>=k)
        {
            for(int i=0; i<n; i++)
                printf("%d",arr[i]);
            printf("\n");
        }
        return;
    }
    arr[pos]=0;
    bin(n,arr,pos+1,k);
    arr[pos]=1;
    bin(n,arr,pos+1,k);
}




int main()
{
    int arr[5];
    int n=4, k=3;
    bin(n,arr,0,k);
}
