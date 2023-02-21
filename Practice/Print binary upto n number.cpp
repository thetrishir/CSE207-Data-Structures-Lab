#include<bits/stdc++.h>
using namespace std;

void printBin(int n, char bin[], int p)
{
    if(p==n)
    {
        bin[p]=0;
        printf("%s\n", bin);
        return;
    }

    bin[p]='0';
    printBin(n, bin, p+1);
    bin[p]='1';
    printBin(n, bin, p+1);
}

int main()
{
    char bin[4];
    printBin(4,bin, 0);

}
