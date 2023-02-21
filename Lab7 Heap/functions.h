#include <bits/stdc++.h>
using namespace std;


/**
    Implement a min-heap below, by completing the un-implemented functions.
    You can assume that the heap will not contain more than
    10^5 (i.e. 100000) elements.

    You can add as many variables within the heap structure
    as you need.
*/
struct Heap{
     int arr[100000];
     int n;
    /**
        If the variables within the heap structure need any form of
        initialization, you can initialize the variables within the
        constructor below. If no initialization is needed, leave it
        blank.
    */
    Heap(){
        n = 0;
    }


    /**
        Add a new value to the heap using the following function.
    */

    void insertValue(int v){
        n = n + 1;
        arr[n - 1] = v;

        for (int i = n / 2 - 1; i >= 0; i--){
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] < arr[smallest])
                smallest = left;
            if (right < n && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i)
                swap(arr[i], arr[smallest]);
        }
    }

    /**
        Return the minimum number in the heap.
        You can assume that the heap is not empty.

        The minimum number should NOT be removed from
        the heap by the getMin function.
    */

    int getMin(){
        return arr[0];
    }
    /**
        Delete the minimum value from the heap.
    */

    void deleteMin(){
        arr[0]=arr[n-1];
        n = n - 1;
        for (int i = n / 2 - 1; i >= 0; i--){
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] < arr[smallest]){
                smallest = left;
            }
            if (right < n && arr[right] < arr[smallest]){
                smallest = right;
            }

            if (smallest != i)
                swap(arr[i], arr[smallest]);
        }
        }
    };
