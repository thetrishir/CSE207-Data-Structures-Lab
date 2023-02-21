#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int index){
	int largest = index; // Initialize largest as root
	int left = 2 * index + 1; // left = 2*i + 1
	int right = 2 * index + 2; // right = 2*i + 2

	// If left child is smaller than root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// If right child is smaller than largest so far
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// If largest is not root
	if (largest != index) {
		swap(arr[index], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}


void buildMaxHeap (int Arr[ ], int N){
    for(int i = (N/2-1) ; i >= 0 ; i-- ){
        heapify (Arr, N, i);
    }
}



void heapSort(int arr[], int n)
{
    //buildMaxHeap(arr, n);
    //  (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = 0; i < n; i++) {
		swap(arr[n-1], arr[i]);		// Move current root to end

		heapify(arr, i, n-1);		// call max heapify on the reduced heap
	}
}



void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << " "<< arr[i] ;
	cout << "\n";
}






void insertNode(int arr[], int& n, int Key)
{
    n = n + 1;    // Increase the size of Heap by 1
    arr[n - 1] = Key;    // Insert the element at end of Heap

    buildMaxHeap(arr, n);
}


void deleteRoot(int arr[], int& n)
{
    buildMaxHeap(arr, n);

    arr[0] = arr[n - 1];    // Replace root with first element

    n = n - 1;    // Decrease size of heap by 1
    heapify(arr, n, 0);    // heapify the root node
}


int maximum(int arr[ ], int n){
    buildMaxHeap(arr, n);
    return arr[ 0 ];
}




// Driver program
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 14, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "\nArray is \n";
	printArray(arr, n);

	buildMaxHeap(arr, n);
	cout << "\nMax heap array is \n";
	printArray(arr, n);

    int key = 15;
    insertNode(arr, n, key);
	cout << "\nInserted array is \n";
	printArray(arr, n);

    deleteRoot(arr, n);
	cout << "\nDeleted array is \n";
    printArray(arr, n);

	heapSort(arr, n);
	cout << "\nSorted array is \n";
	printArray(arr, n);
}
