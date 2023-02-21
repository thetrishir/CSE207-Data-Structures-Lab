#include<bits/stdc++.h>
using namespace std;

int midSearch(int arr[], int v, int first, int last){
    int middle = (first+last)/2;
//printf("\n        f%d    l%d    m%d",first, last, middle);

    if(first>last)
        return -1;

    else if(arr[middle]==v)
        return middle;

    else if(v<arr[middle])
        return midSearch(arr, v, first, middle-1);
    else
        return midSearch(arr, v, middle+1, last);
}


int main(){

	int arr[] = { 2,3,4,6,7,11,13,16,18,21};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "\nArray is \n";
	for (int i = 0; i < n; ++i)
		cout << " "<< arr[i] ;
	cout << "\n";

    int v = 1;
	//cout << "\nInput search value: \n";
    //scanf("%d",&v);
    int c=midSearch(arr,v,0,n-1);
    if(c==-1)
        cout<<"\nNot Found";
    else
        cout<< "\n" << v << " found in index " << c;
    return 0;
}

