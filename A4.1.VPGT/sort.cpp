#include "sort.h"

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // BubbleSort Implementation
    //bubbleSort(arr, n);
    //cout << "BubbleSort" << endl;
    //printArray(arr, n);

    // InsertionSort Implementation
    //insertionSort(arr, n);
    //cout << "InsertionSort" << endl;
    //printArray(arr, n);

    // selectionSort Implementation
    selectionSort(arr, n);
    cout << "selectionSort" << endl;
    printArray(arr, n);

    return 0;
}
