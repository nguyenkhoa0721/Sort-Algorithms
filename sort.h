#include <iostream>
using namespace std;

template <class T>
void swapp(T &a, T &b)
{
    T tmp = b;
    b = a;
    a = tmp;
};
void selectionSort(int arr[], int n)
{
    int i, j, minn;
    for (i = 0; i < n - 1; i++)
    {
        minn = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minn])
                minn = j;
        swapp(arr[minn], arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    int i, j, res;
    for (i = 1; i < n; i++)
    {
        res = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > res)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = res;
    }
}
int findPosition(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (key < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
void binaryInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int res = arr[i];
        int idx = findPosition(arr, 0, i - 1, res);

        for (int j = i - 1; j >= idx; --j)
        {
            arr[j + 1] = arr[j];
        }

        arr[idx] = res;
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swapp(arr[j], arr[j + 1]);
        }
    }
}
void shakerSort(int arr[], int n)
{
    int l, r, k;
    r = n - 1;
    l = 0;
    k = 0;
    while (l < r)
    {
        for (int i = l; i < r; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                k = i;
                swapp(arr[i], arr[i + 1]);
            }
        }
        r = k;
        for (int i = r; i > l; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                k = i;
                swapp(arr[i], arr[i - 1]);
            }
        }
        l = k;
    }
}
void shellSort(int arr[], int n)
{
    for (int i = n / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j - i; k >= 0; k -= i)
            {
                if (arr[k + i] >= arr[k])
                    break;
                else
                    swapp(arr[k + i], arr[k]);
            }
        }
    }
}
void merge(int arr[], int l, int r, int mid)
{
    int *b = new int[r - l + 1];
    int k = 0;
    int p1 = l, p2 = mid;
    while (p1 <= mid - 1 && p2 <= r)
    {
        if (arr[p1] > arr[p2])
        {
            b[k++] = arr[p2];
            p2++;
        }
        else
        {
            b[k++] = arr[p1];
            p1++;
        }
    }
    for (int i = p1; i <= mid - 1; i++)
    {
        b[k++] = arr[i];
    }
    for (int i = p2; i <= r; i++)
    {
        b[k++] = arr[i];
    }
    int j = 0;
    for (int i = l; i <= r; i++)
    {
        arr[i] = b[j++];
    }
    delete[] b;
}
void mergeSort(int arr[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, r, mid + 1);
    }
}
void sift(int heap[], int l, int r, int x)
{
    heap[l] = x;
    int i = l, j = i * 2;
    while (j <= r)
    {
        if (j + 1 <= r && heap[j] > heap[j + 1])
            j++;
        if (heap[j] >= x)
            break;
        heap[i] = heap[j];
        i = j;
        j = 2 * i;
    }
    heap[i] = x;
}
void heapSort(int arr[], int n)
{
    const int oo = 1e8 + 5;
    int *heap = new int[n + 1];
    for (int i = 1; i <= n; i++)
        heap[i] = -oo;
    int *b = new int[n + 1];
    int l = n;
    while (l >= 1)
    {
        sift(heap, l, n, arr[l - 1]);
        l--;
    }
    for (int i = n; i >= 1; i--)
    {
        b[n - i] = heap[1];
        sift(heap, 1, n, oo);
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];
    delete[] heap;
    delete[] b;
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
int getDigit(int x, int exp)
{
    return (x / exp) % 10;
}
void countSort(int arr[], int n, int exp)
{
    int *b = new int[n];
    int *c = new int[10];
    for (int i = 0; i <= 9; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[getDigit(arr[i], exp)]++;
    for (int i = 1; i < 10; i++)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        b[c[getDigit(arr[i], exp)] - 1] = arr[i];
        c[getDigit(arr[i], exp)]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];
    delete[] b;
    delete[] c;
}
void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int i = 1; m / i > 0; i *= 10)
        countSort(arr, n, i);
}
void countingSort(int arr[], int n)
{
    int mx = getMax(arr, n);
    int *b = new int[n + 5];
    int *c = new int[mx + 5];
    for (int i = 0; i <= mx; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[arr[i]]++;
    for (int i = 0; i <= mx; i++)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        b[c[arr[i]] - 1] = arr[i];
        c[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];
    delete[] b;
    delete[] c;
}
// int partition(int arr[], int l, int r)
// {
//     swapp(arr[l],arr[(l+r)/2]);
//     int res = arr[l];
//     int p1 = l;
//     int p2 = r + 1;
//     do
//     {
//         do
//             p1++;
//         while (arr[p1] < res && p1 <= r);
//         do
//             p2--;
//         while (arr[p2] > res && p2 >= l);
//         swapp(arr[p1], arr[p2]);
//     } while (p1 < p2);
//     swapp(arr[p1], arr[p2]);
//     swapp(arr[l], arr[p2]);
//     return p2;
// }
// void quickSort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int mid = partition(arr, l, r);
//         quickSort(arr, l, mid - 1);
//         quickSort(arr, mid + 1, r);
//     }
// }

void quickSort(int a[], int l, int r) {
    // [l, r] hay [l, r)
    if (l >= r) {
        return;
    }
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swapp(a[i++], a[j--]);
        }
    } while (i <= j);
    quickSort(a, l, j);
    quickSort(a, i, r);
}
void flashSort(int arr[], int n)
{
    //classification
    int maxval = arr[0];
    int idx = 0, k;
    int minval = arr[0];
    int m = 0.43 * n;
    int *L = new int[m + 1];
    for (int i = 0; i <= m; i++)
    {
        L[i] = 0;
    }
    L[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
            idx = i;
        }
        if (minval > arr[i])
            minval = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        k = ((float)(m - 1) / (maxval - minval)) * (arr[i] - minval);
        L[k]++;
    }
    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }
    swapp(arr[0], arr[idx]);

    // permutation
    int move = 0;
    int j = 0;
    k = m - 1;
    while (move < n)
    {
        while (j > L[k])
        {
            j++;
            k = ((float)(m - 1) / (maxval - minval)) * (arr[j] - minval);
        }
        int flash = arr[j];
        while (j <= L[k])
        {
            k=((float)(m - 1) / (maxval - minval)) * (flash - minval);
            swapp(arr[L[k]], flash);
            L[k]--;
            move++;
        }
    }

    //insertsort
    for (int k = 0; k < m - 1; k++)
    {
        for (int i = L[k + 1] - 1; i > L[k]; i--)
        {
            int hold;
            if (arr[i] > arr[i + 1])
            {
                hold = arr[i];
                j = i;
                while (hold > arr[j + 1])
                    arr[j++] = arr[j + 1];
                arr[j] = hold;
            }
        }
    }
    delete[] L;
}