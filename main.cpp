#include <iostream>
#include <algorithm>
#include "sort.h"
using namespace std;
int n = 6;
int a[] = {5, 2, 3, 1, 4, 6};
int b[7];
void resetB()
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
int main()
{
    resetB();
    selectionSort(b, n);
    resetB();
    insertionSort(b, n);
    resetB();
    binaryInsertionSort(b, n);
    resetB();
    bubbleSort(b, n);
    resetB();
    shakerSort(b, n);
    resetB();
    shellSort(b, n);
    resetB();
    mergeSort(b, 0, n - 1);
    resetB();
    heapSort(b, n);
    resetB();
    countingSort(b, n);
    resetB();
    radixSort(b, n);
    resetB();
    quickSort(b, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << b[i];
    }
}
