#include <iostream>
#include <math.h>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


class Hierarchy
{
public:
  virtual void sort(int arr[], int n) = 0;
};

class BubbleSort : public Hierarchy
{
public:
  // A function to implement bubble sort
  void sort(int arr[], int n)
  {
     int i, j;
     for (i = 0; i < n-1; i++)

         // Last i elements are already in place
         for (j = 0; j < n-i-1; j++)
             if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);

      //printArray(arr, n);
  }
};

class InsertionSort : public Hierarchy
{
public:
  /* Function to sort an array using insertion sort*/
  void sort(int arr[], int n)
  {
     int i, key, j;
     for (i = 1; i < n; i++)
     {
         key = arr[i];
         j = i-1;

         /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
         while (j >= 0 && arr[j] > key)
         {
             arr[j+1] = arr[j];
             j = j-1;
         }
         arr[j+1] = key;
     }
     //printArray(arr, n);
  }
};

class SelectionSort : public Hierarchy
{
public:
  void sort(int arr[], int n)
  {
      int i, j, min_idx;

      // One by one move boundary of unsorted subarray
      for (i = 0; i < n-1; i++)
      {
          // Find the minimum element in unsorted array
          min_idx = i;
          for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
              min_idx = j;

          // Swap the found minimum element with the first element
          swap(&arr[min_idx], &arr[i]);
      }

      //printArray(arr, n);
  }
};
