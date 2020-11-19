// template <class T>
// void swap(T &a, T &b)
// {
//     T tmp = b;
//     b = a;
//     a = T;
// };
void selectionSort(int arr[], int n)
{
    int i, j, minn;
    for (i = 0; i < n - 1; i++)
    {
        minn = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minn])
                minn = j;
        swap(arr[minn], arr[i]);
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
    return r;
}
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
void shakersort(int arr[], int n)
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
                swap(arr[i], arr[i + 1]);
            }
        }
        r = k;
        for (int i = r; i > l; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                k = i;
                swap(arr[i], arr[i - 1]);
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
                    swap(arr[k + i], arr[k]);
            }
        }
    }
}
void merge(int arr[], int r, int l, int mid)
{
    int *b = new int[l - r + 1];
    int k = 0;
    int p1 = r, p2 = mid;
    while (p1 <= mid - 1 && p2 <= l)
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
        a[i] = b[j++];
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
        mergeSort(arr, mid + 1, l);
        merge(arr, r, l, mid);
    }
}
void sift(int heap[], int n, int x)
{
    int idx = 0;
    int i = 0;
    heap[0] = x;
    while (i < n)
    {
        int j = i * 2;
        if (j >= n)
            break;
        if (j + 1 < n && heap[j] > heap[j + 1])
            j++;
        if (heap[j] > heap[i])
            swap(heap[i], heap[j]);
        else
            break;
        i = j;
    }
}
void heapSort(int arr[], int n){
    
}