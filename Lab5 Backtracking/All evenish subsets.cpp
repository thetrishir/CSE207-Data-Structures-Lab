#include<bits/stdc++.h>
using namespace std;

void allSubsets(int N, int S[], int pos, int len, int subset[])
{
    //printf(" pos%d len%d\n",pos,len);
    if(pos == N)
    {
        int e=0, o=0;
        for(int i=0; i<len; i++)
        {
            if(subset[i]%2==0)
                e++;
            else o++;
        }

        if(e>o)
        {
            for(int i=0; i<len; i++)
                printf("%d, ",subset[i]);
            printf(" \n");
        }
        return;
    }
    // Skip the current element.
    allSubsets(N, S, pos+1, len, subset);
    // Try the current element in the subset.
    subset[len] = S[pos];
    allSubsets(N, S, pos+1, len+1, subset);
}

int main()
{
    int arr[]= {1,4,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sArr[n]= {0};
    allSubsets(n, arr, 0, 0, sArr);
}

