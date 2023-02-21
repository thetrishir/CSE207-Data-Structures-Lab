#include <bits/stdc++.h> 
using namespace std; 


int bin(int n, char arr[], int a, int k){
    int count= 0;
    if(a==n){
        int i=0;
        for(i=0;i<n;i++){
           if(arr[i]=='l'){
           count++;
           }
        }
        if(count>=k){
        printf("%s\n",arr);
        }
        return;
    }
    arr[a]='0';
    bin(n,arr,a+1,k);
    arr[a]='l';
    bin(n,arr,a+1,k);
}


int main(){
    char arr[5];
    bin(4,arr,0,3);
}
