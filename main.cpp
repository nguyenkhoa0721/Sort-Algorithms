#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fstream>
#include "sort.h"
using namespace std;

ofstream fo;
int n;
int data_size[] = {3000, 10000, 30000, 100000, 300000};
int *a;
int *b;
clock_t t;
void preSort()
{
    b = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    t = clock();
}
void printB()
{
    t = clock() - t;
    double time_taken = ((double)t * 1000) / CLOCKS_PER_SEC;
    fo << time_taken << "\n";

    // for (int i = 0; i < 15; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout<<"\n";
    delete[] b;
}
int main()
{
    freopen("data_reverse.txt", "r", stdin);
    fo.open("data_reverse.out", ios::out);
    for (int k = 0; k < 5; k++)
    {
        n = data_size[k];
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n<=300000){
            preSort();
            selectionSort(b, n);
            printB();
            cout << "sS\n";

            preSort();
            insertionSort(b, n);
            printB();
            cout << "iS\n";

            preSort();
            binaryInsertionSort(b, n);
            printB();
            cout << "bIS\n";

            preSort();
            bubbleSort(b, n);
            printB();
            cout << "bS\n";

            preSort();
            shakerSort(b, n);
            printB();
            cout << "shS\n";

            preSort();
            shellSort(b, n);
            printB();
            cout << "shellS\n";
        }
        else{
            for (int i=0;i<6;i++){
                fo<<"-1\n";
            }
        }

        preSort();
        mergeSort(b, 0, n - 1);
        printB();
        cout << "mS\n";

        preSort();
        heapSort(b, n);
        printB();
        cout << "hS\n";

        preSort();
        countingSort(b, n);
        printB();
        cout << "cS\n";

        preSort();
        radixSort(b, n);
        printB();
        cout << "rS\n";

        preSort();
        quickSort(b, 0, n - 1);
        printB();
        cout << "qS\n";

        preSort();
        flashSort(b, n);
        printB();
        cout << "fS\n";

        fo << "\n";
        cout << "\n==== " << n << " ====\n\n";
    }
    delete[] a;
}
