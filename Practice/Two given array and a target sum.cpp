#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int index)
{
	int largest = index; // Initialize largest as root
	int left = 2 * index + 1; // left = 2*i + 1
	int right = 2 * index + 2; // right = 2*i + 2

	// If left child is larger than root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// If largest is not root
	if (largest != index) {
		swap(arr[index], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
    //buildMaxHeap(arr, n);
    //  (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);		// Move current root to end

		heapify(arr, i, 0);		// call max heapify on the reduced heap
	}
}




void sumIndex(int arr[], int r, int arrb[], int c, int target){
        //printf("\n      arr %d and arrb %d\n",r,c);
	if(r>6 || c<0)
        return;

    else if(arr[r]+arrb[c]==target){
        printf("\narr %d and arrb %d      %d, %d,   %d",r,c,arr[r],arrb[c],arr[r]+arrb[c]);
        return sumIndex(arr, r+1, arrb, c-1, target);
    }
    else if(arr[r]+arrb[c]<target)
        return sumIndex(arr, r+1, arrb, c, target);
    else
        return sumIndex(arr, r, arrb, c-1, target);
}


int main(){

	int arr[] = { 0, 12, 9, 2, 6, 14, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int arrb[] = { 4,16,3,5,1,10,8 };
	int nb = sizeof(arrb)/sizeof(arrb[0]);

	heapSort(arr,n);
	heapSort(arrb,nb);

	cout << "\nArray is \n";
	for (int i = 0; i < n; ++i)
		cout << "  "<< arr[i] ;
	cout << "\n";
	for (int i = 0; i < n; ++i)
		cout << "  "<< arrb[i] ;
	cout << "\n";

	int target=13;
	sumIndex(arr, 0, arrb, nb-1, target);
	/*int r = 0;
	int c = 7-1;
	while(r<=n){
            printf("\narr %d and arrb %d      %d, %d,   %d",r,c,arr[r],arrb[c],arr[r]+arrb[c]);
        if(arr[r]+arrb[c]==target){
            printf("\narr %d and arrb %d",r,c);
            r++;
            c--;
        }
        else if(arr[r]+arrb[c]<target)
            r++;
        else c--;
	}
            printf("\narr %d and arrb %d",r,c+200);*/
}
